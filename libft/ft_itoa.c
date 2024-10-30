/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:08:30 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/19 12:00:06 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_num(int nbr)
{
	int	cnt;

	cnt = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		cnt++;
	while (nbr != 0)
	{
		nbr /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_rev_str(char *str, int size)
{
	int		i;
	char	swap;

	i = 0;
	while (i < (size / 2))
	{
		swap = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = swap;
		i++;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	long long	num;
	int			cnt;
	char		*arr;
	int			i;

	num = nbr;
	cnt = ft_cnt_num(num);
	i = 0;
	arr = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!(arr))
		return (NULL);
	if (num < 0)
	{
		arr[cnt - 1] = '-';
		num *= -1;
	}
	if (num == 0)
		arr[i] = '0';
	while (num != 0)
	{
		arr[i++] = (num % 10) + '0';
		num /= 10;
	}
	arr[cnt] = 0;
	return (ft_rev_str(arr, cnt));
}
