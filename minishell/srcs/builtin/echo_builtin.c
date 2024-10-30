/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:16:14 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/15 16:39:05 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_opt(char *arg)
{
	int	index;

	if (arg[0] != '-')
		return (1);
	index = 1;
	while (arg[index] == 'n')
		index += 1;
	if (index == 1 || arg[index] != 0)
		return (1);
	return (0);
}

int	echo_builtin(char **cmd)
{
	int		index;
	int		new_line_option;

	index = 1;
	new_line_option = 1;
	while (cmd[index] != 0)
	{
		if (index == 1 && check_opt(cmd[index]) == 0)
			new_line_option = 0;
		else
			ft_putstr(cmd[index], 1);
		index += 1;
	}
	if (new_line_option == 1)
		ft_putchar('\n', 1);
	return (0);
}
