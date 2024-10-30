/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:17:11 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/15 15:38:43 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		index;

	index = 0;
	while (index + 1 < dstsize && src[index] != 0)
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize > 0)
		dst[index] = 0;
	index = 0;
	while (src[index] != 0)
		index++;
	return (index);
}
