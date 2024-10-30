/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:12:08 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/01 12:25:53 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <errno.h>
# include "../libft/libft.h"

# define INFINITE 1
# define NOT_LAST 0
# define LAST 1

enum e_token
{
	CHAR = -1,
	CHAR_WHITESPACE = ' ',
	CHAR_TAB = '\t',
	PIPE = '|',
	QOUTE = '\'',
	DQOUTE = '\"',
	L = '<',
	R = '>',
	LL = 44,
	RR = 45,
	CHAR_NULL = '\0',
};

enum e_state
{
	GENERAL,
	STATE_DQOUTE,
	STATE_QOUTE,
	STATE_SPACE,
	STATE_L,
	STATE_R,
};

enum e_builtin
{
	E_ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
};

typedef struct s_token
{
	char			*value;
	int				str_len;
	int				index;
	enum e_token	type;
	struct s_token	*next;
}	t_token;

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*prev;
	struct s_envp	*next;
}	t_envp;

typedef struct s_redirection
{
	int						type;
	char					*filename;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_stage
{
	char					**cmd;
	char					*cmd_path;
	int						in_fd;
	int						out_fd;
	int						stdin_temp;
	int						stdout_temp;
	int						pipe[2];
	pid_t					pid;
	int						exit_code;
	char					*heredoc_name;
	struct s_redirection	*input;
	struct s_stage			*prev;
	struct s_stage			*next;
}	t_stage;

typedef struct s_path
{
	char			*str;
	struct s_path	*prev;
	struct s_path	*next;
}	t_path;

// parse.c
t_stage		*parse(char *input, t_envp *envp, int *exit_code);

// parse_util.c
int			count_cmd(t_token *token);
t_stage		*new_stage(void);
void		get_cmd(t_token *token, t_stage *res);
t_token		*del_space(t_token *token);

// syntex_check.c
int			check_syntex_err(t_token *token);

// lexer.c
t_token		*lexer(char *input);

// lexer_util.c
t_token		*lexer_general_pipe(t_token *cur, int ctype, char input);
t_token		*lexer_general(t_token *cur, int *state, char input);
t_token		*lexer_qoute(t_token *cur, int *state, char input);
t_token		*lexer_redirection(t_token *cur, int *state, char **input);
t_token		*lexer_space(t_token *cur, int *state, char **input);

// t_token_util.c
int			get_type(char c);
int			get_status(int type);
t_token		*new_token(int size);
void		push_char(t_token *token, char c);
void		free_token(t_token *token);

// syntex_check.c
int			check_syntex_err(t_token *token);

// translate.c
void		translate_value(t_token *token, t_envp *envp, int exit_code);

// translate_util.c
char		*get_envp_value(char *start, t_envp *envp);
char		*get_front(t_token *token, char *start, t_envp *envp);
char		*get_tail(char *start, int key_len, char *res);

// echo_process.c
t_token		*echo_process(t_token *token);

// del_redirection.c
t_token		*del_token(t_token *root, t_token *target);
t_token		*del_redierction(t_token *token);

// get_redirection.c
t_stage		*get_redirection(t_token *token);

// ft_readline.c
char		*ft_readline(int *exit_code);

// envp_to_list.c
void		envp_to_list(t_envp **my_envp, char *envp[]);
t_envp		*new_envp(char *env);
void		add_envp_back(t_envp **head, t_envp **new);

// open_file.c
int			open_file(t_stage *stage);

// process_heredoc.c
void		process_heredoc(t_stage *stage);
void		name_tmpfile(t_stage *stage);
void		check_heredoc_number(t_stage *stage);

// list_to_envp.c
char		**list_to_envp(t_envp *my_envp);

// get_path.c
char		*get_path(t_envp *my_envp, char **cmd);

// get_path_util_1.c
char		*get_relative_path(char *cmd, t_envp *my_envp);
char		*get_absolute_path(char *cmd, t_envp *my_envp);

// get_path_util_2.c
t_path		*new_path(char *str);
void		add_path_back(t_path **path, t_path *new);
void		delete_last_path(t_path **path);
void		free_path(t_path *path);

// get_path_util_3.c
void		add_cmd_to_path(char **cmd_split, t_path **path);
void		add_home_to_path(char *home, t_path **path);
char		*connect_path(t_path *path);

// run_stages.c
int			run_stages(t_stage *stage, t_envp **my_envp, int exit_code);

// exec_cmd.c
int			exec_cmd(t_stage *stage, t_envp **my_envp);
void		std_temp(t_stage *stage, int flag);

// exec_util.c
void		set_redirection(t_stage *stage);
void		child_process(t_stage *stage, t_envp **my_envp, char **env_arr);

// exec_builtin.c
int			exec_builtin(t_stage *stage, t_envp **my_envp);
int			chk_builtin(t_stage *stage);

// signal.c
void		init_sig(void);
void		init_sig_child(void);
void		mode_terminal_sig(void);
void		init_heredoc(void);

// signal_handler.c
void		receive_int(int signo, siginfo_t *info, void *context);
void		receive_quit(int signo, siginfo_t *info, void *context);
void		in_heredoc(int signo, siginfo_t *info, void *context);
void		receive_int_terminal(int signo, siginfo_t *info, void *context);

// terminal_set.c
int			restore_terminal(void);
int			init_terminal(void);

// builtin functions

// cd_builtin.c
int			cd_builtin(t_envp *my_envp, char *dir);
char		*get_home(t_envp *my_envp);

// cd_builtin_util.c
char		*get_relative_path_cd(char *cmd, t_envp *my_envp);

// echo_builtin.c
int			echo_builtin(char **cmd);

// env_builtin.c
int			env_builtin(t_envp *my_envp, t_stage *stage);

// exit_builtin.c
void		exit_builtin(t_stage *stage);

// export_builtin.c
void		export_envp(t_envp **my_envp, t_envp **new);
int			export_builtin(t_envp *my_envp, char **cmd);

// pwd_builtin.c
int			pwd_builtin(void);

// unset_builtin.c
int			unset_builtin(t_envp **my_envp, t_stage *stage);

// wait_process.c
int			wait_process(t_stage *stage);

// free_stages.c
void		free_stages(t_stage *stage);
void		*free_strs(char **strs);
void		close_pipe(t_stage *stage);
void		close_all_pipe(t_stage *stage);

int			chdir_err(char *pwd, char *dst);

#endif
