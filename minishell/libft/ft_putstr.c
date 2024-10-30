/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:16:59 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/03/15 18:34:18 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* success : 0 | failure : -1 */
int	ft_putstr(char *str, int fd)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (ft_putchar(str[i], fd) < 0)
			return (-1);
		i++;
	}
	return (0);
}
