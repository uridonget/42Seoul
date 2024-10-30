/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:10:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 10:30:34 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_builtin(t_envp *my_envp, t_stage *stage)
{
	if (stage->cmd_path == NULL)
	{
		ft_putstr("env: No such file or directory\n", 2);
		return (127);
	}
	if (!(my_envp))
		return (1);
	while (my_envp)
	{
		ft_putstr(my_envp->key, 1);
		ft_putchar('=', 1);
		ft_putstr(my_envp->value, 1);
		ft_putchar('\n', 1);
		my_envp = my_envp->next;
	}
	return (0);
}
