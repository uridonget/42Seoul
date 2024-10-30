/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:26:31 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/20 12:55:59 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_sig_child(void)
{
	struct sigaction	sig_int;
	struct sigaction	sig_quit;

	sigemptyset(&(sig_int.sa_mask));
	sigemptyset(&(sig_quit.sa_mask));
	sig_int.sa_flags = SA_SIGINFO;
	sig_int.sa_sigaction = (void *)SIG_DFL;
	sig_quit.sa_flags = SA_SIGINFO;
	sig_quit.sa_sigaction = (void *)SIG_DFL;
	sigaction(SIGINT, &sig_int, 0);
	sigaction(SIGQUIT, &sig_quit, 0);
}

void	mode_terminal_sig(void)
{
	struct sigaction	sig_int;

	sigemptyset(&(sig_int.sa_mask));
	sig_int.sa_flags = SA_SIGINFO;
	sig_int.sa_sigaction = receive_int_terminal;
	sigaction(SIGINT, &sig_int, 0);
}

void	init_sig(void)
{
	struct sigaction	sig_int;
	struct sigaction	sig_quit;

	sigemptyset(&(sig_int.sa_mask));
	sigemptyset(&(sig_quit.sa_mask));
	sig_int.sa_flags = SA_SIGINFO;
	sig_int.sa_sigaction = receive_int;
	sig_quit.sa_flags = SA_SIGINFO;
	sig_quit.sa_sigaction = receive_quit;
	sigaction(SIGINT, &sig_int, 0);
	sigaction(SIGQUIT, &sig_quit, 0);
}

void	init_heredoc(void)
{
	struct sigaction	sig_int;
	struct sigaction	sig_quit;

	sigemptyset(&(sig_int.sa_mask));
	sigemptyset(&(sig_quit.sa_mask));
	sig_int.sa_flags = SA_SIGINFO;
	sig_int.sa_sigaction = (void *)SIG_DFL;
	sig_quit.sa_flags = SA_SIGINFO;
	sig_quit.sa_sigaction = in_heredoc;
	sigaction(SIGINT, &sig_int, 0);
	sigaction(SIGQUIT, &sig_quit, 0);
}
