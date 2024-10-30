/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:13:39 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/01 12:25:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern int	g_status;

int	chdir_err(char *pwd, char *dst)
{
	ft_putstr("minishell: ", 2);
	perror("");
	free(pwd);
	free(dst);
	return (1);
}

static void	init_minishell(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr("There should be no argument\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	chk_g_status(int *exit_code)
{
	if (g_status == SIGINT)
	{
		if (*exit_code != 130)
			*exit_code = 1;
		g_status = 0;
	}
}

int	main(int ac, char *av[], char *envp[])
{
	char		*line;
	t_envp		*my_envp;
	t_stage		*stage;
	int			exit_code;

	init_minishell(ac, av);
	envp_to_list(&my_envp, envp);
	exit_code = 0;
	while (INFINITE)
	{
		init_sig();
		if (init_terminal() == 1)
			exit(1);
		g_status = 0;
		line = ft_readline(&exit_code);
		if (line == NULL)
			continue ;
		chk_g_status(&exit_code);
		stage = parse(line, my_envp, &exit_code);
		if (stage == NULL)
			continue ;
		mode_terminal_sig();
		exit_code = run_stages(stage, &my_envp, exit_code);
	}
	return (EXIT_SUCCESS);
}
