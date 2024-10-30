/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:31:20 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/21 13:05:25 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(const char c)
{
	if ((c == ' ') || (c == '\t')
		|| (c == '\n') || (c == '\v')
		|| (c == '\f') || (c == '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			minus;
	long long	num;

	minus = 0;
	num = 0;
	while (ft_is_space(*str) == 1)
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
	return ((int)num);
}
