/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:40:53 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/03 10:33:28 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_set(char c, char	const *set)
{
	int	index;

	if (set == 0)
		return (0);
	index = 0;
	while (set[index] != 0)
	{
		if (set[index] == c)
		{
			return (1);
		}
		index++;
	}
	return (0);
}

static int	count_len(char const *s1, char const *set)
{
	int	count;
	int	index;
	int	s_len;

	if (set == 0)
		return (0);
	s_len = ft_strlen(s1);
	index = 0;
	count = 0;
	while (is_set(s1[index], set) == 1)
		index++;
	count += index;
	if (count != s_len)
	{
		index = 0;
		while (is_set(s1[s_len - index - 1], set) == 1)
			index++;
		count += index;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_len;
	int		index;
	int		res_index;
	char	*res;

	index = 0;
	if (s1 == 0)
		exit(EXIT_FAILURE);
	s1_len = count_len(s1, set);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) - s1_len + 1));
	if (res == 0)
		exit(EXIT_FAILURE);
	index = 0;
	while (is_set(s1[index], set) == 1)
		index++;
	res_index = 0;
	while (res_index < (int)ft_strlen(s1) - s1_len)
	{
		res[res_index] = s1[index];
		index++;
		res_index++;
	}
	res[res_index] = 0;
	return (res);
}
