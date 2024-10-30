/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:36:04 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/07 11:52:22 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*arr;

	len = ft_strlen(src);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(arr))
		return (0);
	i = 0;
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
