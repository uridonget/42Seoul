/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:28:36 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/25 11:37:19 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_vars
{
	int		cmd_num;
	int		infile;
	int		outfile;
	char	***cmd;
	char	**cmd_path;
}	t_vars;

// ft_init.c
void	ft_init(t_vars *vars, int ac, char *av[], char *envp[]);

// open_file.c
void	open_file(t_vars *vars, int ac, char *av[]);

// set_path.c
void	set_path(t_vars *vars, char *av[], char *envp[]);

// free_close.c
void	free_double(char **dou);
void	free_triple(char ***tri);
void	close_fd(t_vars *vars);
void	free_close(t_vars *vars);
void	fail_exit(char *err_msg);

// exec_cmd.c
void	exec_cmd(t_vars *vars, int i, char *envp[]);

#endif
