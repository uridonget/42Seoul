/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:55:49 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/09 17:16:35 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || \
		c == '\r' || c == ' ')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			minus;
	long long	num;

	minus = 0;
	num = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (('0' <= *str) && (*str <= '9'))
	{
		num = 10 * num + (*str - 48);
		str++;
	}
	if (minus == 1)
		num *= -1;
	return (num);
}
