/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:12:36 by haejeong          #+#    #+#             */
/*   Updated: 2023/11/07 16:48:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *cnt)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	(*cnt)++;
	return (1);
}

int	ft_putstr(char *str, int *cnt)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_putchar(str[i], cnt) < 0)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_print_c(char c, int *cnt)
{
	if (ft_putchar(c, cnt) < 0)
		return (-1);
	return (1);
}

int	ft_print_s(char *str, int *cnt)
{
	size_t	i;

	i = 0;
	if (!(str))
	{
		if (ft_putstr("(null)", cnt) < 0)
			return (-1);
		return (1);
	}
	while (str[i])
	{
		if (ft_putchar(str[i], cnt) < 0)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_print_d_i(int n, int *cnt)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		if (ft_putchar('-', cnt) < 0)
			return (-1);
		num *= -1;
	}
	if (num >= 10)
	{
		if (ft_print_d_i(num / 10, cnt) < 0)
			return (-1);
	}
	if (ft_putchar(num % 10 + '0', cnt) < 0)
		return (-1);
	return (1);
}
