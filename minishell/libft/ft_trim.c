/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:00:03 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/21 13:02:47 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	int		flag;

	flag = 0;
	if (c == '\t')
		flag = 1;
	else if (c == '\n')
		flag = 1;
	else if (c == '\v')
		flag = 1;
	else if (c == '\f')
		flag = 1;
	else if (c == '\r')
		flag = 1;
	else if (c == ' ')
		flag = 1;
	return (flag);
}

char	*ft_trim(const char *str)
{
	char		*new;
	size_t		start;
	size_t		end;

	if (!(str))
		return (NULL);
	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && ft_isspace(str[start]))
		start++;
	while (str[end] && ft_isspace(str[end]))
		end--;
	new = ft_substr(str, start, end - start + 1);
	if (!(new))
		return (NULL);
	return (new);
}
