/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:19:20 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/07 09:18:05 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	if (!s)
		return (0);
	while (s[res] != 0)
	{
		res++;
	}
	return (res);
}

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*res;
	int		index;

	length = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (res == 0)
		return (0);
	index = 0;
	while (index < length)
	{
		res[index] = s1[index];
		index++;
	}
	res[length] = 0;
	return (res);
}
