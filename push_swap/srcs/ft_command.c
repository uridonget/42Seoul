/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:23:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/12 14:33:06 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static void	write_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		write(1, &cmd[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_command(t_vars *vars, char *cmd, int flag)
{
	if (flag == 1)
		write_cmd(cmd);
	if (ft_strcmp(cmd, "pa") == 0)
		return (pa(vars));
	else if (ft_strcmp(cmd, "pb") == 0)
		return (pb(vars));
	else if (ft_strcmp(cmd, "sa") == 0)
		return (sa(vars->a));
	else if (ft_strcmp(cmd, "sb") == 0)
		return (sb(vars->b));
	else if (ft_strcmp(cmd, "ss") == 0)
		return (ss(vars));
	else if (ft_strcmp(cmd, "ra") == 0)
		return (ra(vars->a));
	else if (ft_strcmp(cmd, "rb") == 0)
		return (rb(vars->b));
	else if (ft_strcmp(cmd, "rr") == 0)
		return (rr(vars));
	else if (ft_strcmp(cmd, "rra") == 0)
		return (rra(vars->a));
	else if (ft_strcmp(cmd, "rrb") == 0)
		return (rrb(vars->b));
	else if (ft_strcmp(cmd, "rrr") == 0)
		return (rrr(vars));
	return (0);
}
