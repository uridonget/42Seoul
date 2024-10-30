CC = cc 
CFLAGS = -Wall -Wextra -Werror

# haejeong ver
LDFLAGS = -lreadline -L/Users/haejeong/.brew/opt/readline/lib
CPPFLAGS = -I/Users/haejeong/.brew/opt/readline/include

# sanghyan ver
# LDFLAGS = -lreadline -L/Users/sangyhan/.brew/opt/readline/lib
# CPPFLAGS = -I/Users/sangyhan/.brew/opt/readline/include

NAME	= minishell

SRCS	= ./srcs/main.c \
		  ./srcs/echo_process.c \
		  ./srcs/run_stages.c \
		  ./srcs/envp_to_list.c \
		  ./srcs/ft_readline.c \
		  ./srcs/list_to_envp.c \
		  ./srcs/get_path.c \
		  ./srcs/get_path_util_1.c \
		  ./srcs/get_path_util_2.c \
		  ./srcs/get_path_util_3.c \
		  ./srcs/get_redirection.c \
		  ./srcs/del_redirection.c \
		  ./srcs/open_file.c \
		  ./srcs/process_heredoc.c \
		  ./srcs/lexer.c \
		  ./srcs/lexer_util.c \
		  ./srcs/parse.c \
		  ./srcs/parse_util.c \
		  ./srcs/t_token_util.c \
		  ./srcs/syntex_check.c \
		  ./srcs/exec_cmd.c \
		  ./srcs/exec_builtin.c \
		  ./srcs/exec_util.c \
		  ./srcs/wait_process.c \
		  ./srcs/builtin/env_builtin.c \
		  ./srcs/builtin/exit_builtin.c \
		  ./srcs/builtin/echo_builtin.c \
		  ./srcs/builtin/export_builtin.c \
		  ./srcs/builtin/unset_builtin.c \
		  ./srcs/builtin/pwd_builtin.c \
		  ./srcs/builtin/cd_builtin.c \
		  ./srcs/builtin/cd_builtin_util.c \
		  ./srcs/translate.c \
		  ./srcs/translate_util.c \
		  ./srcs/terminal_set.c \
		  ./srcs/signal.c \
		  ./srcs/signal_handler.c \
		  ./srcs/free_stages.c \

LIBFT_A = ./libft/libft.a

OBJS	= $(SRCS:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT_A) :
	$(MAKE) -C ./libft all

clean 	:
	$(MAKE) -C ./libft clean;
	rm -rf $(OBJS)

fclean  : clean
	$(MAKE) -C ./libft fclean;
	rm -rf $(NAME)

re		:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
