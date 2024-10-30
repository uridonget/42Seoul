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

void	*ft_calloc(size_t	len, size_t	size)
{
	void	*arr;

	arr = (void *)malloc(size * len);
	if (!(arr))
		return (NULL);
	if (size * len)
		ft_bzero(arr, size * len);
	return (arr);
}
