/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:50:20 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/03 10:33:35 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	index;

	if (s == 0)
		exit(EXIT_FAILURE);
	if (ft_strlen(s) < (size_t)start + len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < (size_t)start)
		len = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		exit(EXIT_FAILURE);
	index = 0;
	while (index < len && s[start + index] != 0)
	{
		res[index] = s[start + index];
		index++;
	}
	res[index] = 0;
	return (res);
}
