/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:11:18 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/20 08:48:49 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			index;
	unsigned char	to_write;

	to_write = (unsigned char)c;
	str = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		str[index] = to_write;
		index++;
	}
	return (b);
}
