/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:32:20 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/05 11:17:13 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	size;

	if (!(s))
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		arr = (char *)malloc(sizeof(char) * 1);
	else if (start + len > size)
		arr = (char *)malloc(sizeof(char) * (size - start + 1));
	else
		arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(arr))
		return (NULL);
	i = 0;
	while ((i < len) && ((start + i) < size))
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
