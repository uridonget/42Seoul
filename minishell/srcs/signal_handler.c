/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:34:42 by sangyhan          #+#    #+#             */
/*   Updated: 2024/04/01 09:28:19 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		g_status;

void	receive_int(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_status = signo;
}

void	receive_quit(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)signo;
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

void	in_heredoc(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)signo;
	return ;
}

void	receive_int_terminal(int signo, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	g_status = signo;
}
