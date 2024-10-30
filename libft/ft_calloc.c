/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:10:50 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/21 14:37:15 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*arr;

	arr = (void *)malloc(size * len);
	if (!(arr))
		return (NULL);
	if (size * len)
		ft_bzero(arr, size * len);
	return (arr);
}
