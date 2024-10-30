/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:29:52 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/12 10:20:31 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	while ((src[i]) && (i + d_len + 1 < dstsize))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = 0;
	if (dstsize > d_len)
		return (d_len + s_len);
	else
		return (dstsize + s_len);
}
