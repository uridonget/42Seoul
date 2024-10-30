/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:30:08 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/19 12:03:35 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*needle))
		return ((char *)&haystack[i]);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (len < i + j)
				return (0);
			else if (!(needle[j]))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
