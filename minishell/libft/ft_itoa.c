/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:38:05 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/15 10:26:37 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		res = res + 2;
		n = n / 10;
		n = n * -1;
	}
	while (n > 0)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

static void	write_i(int n, int len, char *res)
{
	char	c;

	res[len] = 0;
	len--;
	if (n == 0)
		res[len] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		c = -1 * (n % 10);
		res[len] = '0' + c;
		n = n / 10;
		n = n * -1;
		len--;
	}
	while (n > 0)
	{
		c = n % 10;
		res[len] = '0' + c;
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = get_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	write_i(n, len, res);
	return (res);
}
