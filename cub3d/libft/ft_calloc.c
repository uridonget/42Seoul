/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:14:05 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/20 08:53:09 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	index;

	if (size != 0 && (count * size) / size != count)
		return (0);
	res = (char *)malloc(count * size);
	if (res == 0)
		return (0);
	index = 0;
	while (index < count * size)
	{
		res[index] = 0;
		index++;
	}
	return ((void *)res);
}
