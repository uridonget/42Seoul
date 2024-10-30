/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:27:23 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 14:53:35 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static long long	safe_add(long long res, int num)
{
	long long	temp;

	temp = res;
	res = res * 10 + num;
	if ((num < 0 && temp < res) || (num > 0 && temp > res))
		return (-1);
	return (0);
}

static int	check_arg_valid(const char *str)
{
	int			idx;
	int			sign;
	long long	res;

	if (!(str))
		exit(EXIT_FAILURE);
	res = 0;
	sign = 1;
	idx = 0;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (ft_isdigit(str[idx]))
	{
		if (safe_add(res, (str[idx] - '0') * sign) != 0)
			return (-1);
		res = res * 10 + (str[idx] - '0') * sign;
		idx++;
	}
	if (str[idx])
		return (-1);
	return (0);
}

static int	ft_atoi_not_safe(const char *str)
{
	int			index;
	int			sign;
	long		res;

	res = 0;
	sign = 1;
	index = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + (str[index] - '0') * sign;
		index++;
	}
	return ((int)res);
}

static int	chk_exit_arg(char **cmd)
{
	char	*str_trim;
	int		res;

	if (ft_strslen(cmd) == 1)
		return (0);
	str_trim = ft_trim(cmd[1]);
	if (!(str_trim))
		exit(EXIT_FAILURE);
	if (check_arg_valid(str_trim) == -1)
	{
		free(str_trim);
		ft_putstr("minishell: exit: ", 2);
		ft_putstr(cmd[1], 2);
		ft_putstr(": numeric argument required\n", 2);
		return (255);
	}
	if (ft_strslen(cmd) > 2)
	{
		free(str_trim);
		ft_putstr("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	res = ft_atoi_not_safe(str_trim);
	free(str_trim);
	return (res);
}

void	exit_builtin(t_stage *stage)
{
	int		exit_code;

	if (ft_strslen(stage->cmd) > 1)
		exit_code = chk_exit_arg(stage->cmd);
	else
		exit_code = stage->exit_code;
	if (stage->pid != 0)
		ft_putstr("exit\n", 1);
	close_pipe(stage);
	if (stage->heredoc_name)
		unlink(stage->heredoc_name);
	if (stage->prev == NULL && stage->next == NULL)
	{
		if (restore_terminal() == 1)
			exit(1);
	}
	exit(exit_code);
}
