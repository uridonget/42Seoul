/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:24:59 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/19 17:56:50 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char c)
{
	int		flag;

	flag = 0;
	if (c == '\t')
		flag = 1;
	else if (c == '\n')
		flag = 1;
	else if (c == '\v')
		flag = 1;
	else if (c == '\f')
		flag = 1;
	else if (c == '\r')
		flag = 1;
	else if (c == ' ')
		flag = 1;
	return (flag);
}

static long	safe_add(long res, int num)
{
	long	temp;

	temp = res;
	res = res * 10 + num;
	if (num < 0 && temp < res)
		return (0);
	if (num > 0 && temp > res)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			index;
	int			sign;
	long		res;

	res = 0;
	sign = 1;
	index = 0;
	while (ft_isspace(str[index]) == 1)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if (safe_add(res, (str[index] - '0') * sign) != 1)
			return (safe_add(res, (str[index] - '0') * sign));
		res = res * 10 + (str[index] - '0') * sign;
		index++;
	}
	return ((int)res);
}
