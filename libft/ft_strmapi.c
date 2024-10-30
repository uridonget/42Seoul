/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:53:03 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/19 12:03:22 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*arr;

	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(arr))
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
