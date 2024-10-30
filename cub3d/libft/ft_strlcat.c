/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:17:42 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/19 14:36:20 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		index;
	size_t		dst_len;
	size_t		src_len;

	if (dstsize == 0 && dst == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (index + dst_len + 1 < dstsize && src[index] != 0)
	{
		dst[index + dst_len] = src[index];
		index++;
	}
	dst[index + dst_len] = 0;
	return (dst_len + src_len);
}
