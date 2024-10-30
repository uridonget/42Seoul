/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:03:35 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/19 12:04:08 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chk_forward(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (ft_strchr(set, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_chk_backward(char const *s, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (s1 == 0)
		return (NULL);
	if (set == 0)
		return (ft_strdup(s1));
	start = ft_chk_forward(s1, set);
	end = ft_chk_backward(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!(res))
		return (NULL);
	ft_strlcpy(res, s1 + start, end - start + 1);
	return (res);
}
