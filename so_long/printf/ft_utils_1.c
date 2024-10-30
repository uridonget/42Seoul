/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:00:15 by haejeong          #+#    #+#             */
/*   Updated: 2023/11/07 16:38:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!(str))
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	ft_check(char c, va_list argptr, int *cnt)
{
	if (c == 'c')
		return (ft_print_c(va_arg(argptr, int), cnt));
	else if (c == 's')
		return (ft_print_s(va_arg(argptr, char *), cnt));
	else if (c == 'd' || c == 'i')
		return (ft_print_d_i(va_arg(argptr, int), cnt));
	else if (c == 'p')
		return (ft_print_p(va_arg(argptr, void *), cnt));
	else if (c == 'u')
		return (ft_print_u(va_arg(argptr, unsigned int), cnt));
	else if (c == 'x')
		return (ft_print_lx(va_arg(argptr, unsigned int), cnt));
	else if (c == 'X')
		return (ft_print_ux(va_arg(argptr, unsigned int), cnt));
	else if (c == '%')
		return (ft_print_per(cnt));
	return (0);
}

int	ft_write_str(const char *str, va_list argptr)
{
	size_t	len;
	size_t	i;
	int		cnt;

	len = ft_strlen(str);
	i = 0;
	cnt = 0;
	while (i < len)
	{
		if ((str[i] == '%') && (i < len - 1))
		{
			if (ft_check(str[i + 1], argptr, &cnt) < 0)
				return (-1);
			i += 2;
		}
		else
		{
			if (ft_putchar(str[i], &cnt) < 0)
				return (-1);
			i++;
		}
	}
	return (cnt);
}
