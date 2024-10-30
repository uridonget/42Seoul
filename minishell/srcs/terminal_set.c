/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:58:27 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/19 18:28:16 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	init_terminal(void)
{
	struct termios	term;

	while (tcgetattr(STDIN_FILENO, &term) == -1)
	{
		if (errno == EINTR)
			continue ;
		else
			return (1);
	}
	term.c_lflag &= ~ECHOCTL;
	term.c_cc[VQUIT] = _POSIX_VDISABLE;
	while (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
	{
		if (errno == EINTR)
			continue ;
		else
			return (1);
	}
	return (0);
}

int	restore_terminal(void)
{
	struct termios	term;

	while (tcgetattr(STDIN_FILENO, &term) == -1)
	{
		if (errno == EINTR)
			continue ;
		else
			return (1);
	}
	term.c_lflag |= ECHOCTL;
	term.c_cc[VQUIT] = 28;
	while (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
	{
		if (errno == EINTR)
			continue ;
		else
			return (1);
	}
	return (0);
}
