/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:31:25 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/22 13:57:14 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
