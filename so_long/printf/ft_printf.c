/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:05:27 by haejeong          #+#    #+#             */
/*   Updated: 2023/11/08 19:06:01 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chk_char(char c)
{
	char	*type;
	int		i;

	type = "cspdiuxX";
	i = 0;
	while (type[i])
	{
		if (c == type[i])
			return (1);
		i++;
	}
	if (c == '%')
		return (1);
	return (-1);
}

static int	ft_chk_str(const char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if ((str[i] == '%') && (i < len -1))
		{
			if (ft_chk_char(str[i + 1]) < 0)
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		cnt;
	va_list	argptr;

	if (!(ft_chk_str(str)))
		return (-1);
	va_start(argptr, str);
	cnt = ft_write_str(str, argptr);
	va_end(argptr);
	return (cnt);
}
