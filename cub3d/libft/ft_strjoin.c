/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:17:03 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/19 14:38:46 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	index;
	char	*res;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (res == 0)
		return (0);
	index = 0;
	while (s1[index] != 0)
	{
		res[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index] != 0)
	{
		res[s1_len + index] = s2[index];
		index++;
	}
	res[s1_len + ft_strlen(s2)] = 0;
	return (res);
}
