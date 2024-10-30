/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:24:58 by haejeong          #+#    #+#             */
/*   Updated: 2023/11/07 16:55:49 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *ptr, int *cnt)
{
	char				*hex;
	int					i;
	unsigned long int	num;
	char				add[16];

	hex = "0123456789abcdef";
	num = (unsigned long int)ptr;
	if (ft_putstr("0x", cnt) < 0)
		return (-1);
	if (!(num))
	{
		if (ft_putchar('0', cnt) < 0)
			return (-1);
		return (1);
	}
	i = -1;
	while (num != 0)
	{
		add[++i] = hex[num % 16];
		num /= 16;
	}
	while (i >= 0)
		if (ft_putchar(add[i--], cnt) < 0)
			return (-1);
	return (1);
}

int	ft_print_u(unsigned int n, int *cnt)
{
	if (n >= 10)
		if (ft_print_u(n / 10, cnt) < 0)
			return (-1);
	if (ft_putchar(n % 10 + '0', cnt) < 0)
		return (-1);
	return (1);
}

int	ft_print_lx(unsigned int n, int *cnt)
{
	char	*hex;
	int		i;
	char	lst[16];

	hex = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		if (ft_putchar('0', cnt) < 0)
			return (-1);
	}
	else
	{
		while (n != 0)
		{
			lst[i++] = hex[n % 16];
			n /= 16;
		}
		i--;
		while (i >= 0)
			if (ft_putchar(lst[i--], cnt) < 0)
				return (-1);
	}
	return (1);
}

int	ft_print_ux(unsigned int n, int *cnt)
{
	char	*hex;
	int		i;
	char	lst[15];

	hex = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
	{
		if (ft_putchar('0', cnt) < 0)
			return (-1);
	}
	else
	{
		while (n != 0)
		{
			lst[i++] = hex[n % 16];
			n /= 16;
		}
		i--;
		while (i >= 0)
			if (ft_putchar(lst[i--], cnt) < 0)
				return (-1);
	}
	return (1);
}

int	ft_print_per(int *cnt)
{
	if (ft_putchar('%', cnt) < 0)
		return (-1);
	return (1);
}
