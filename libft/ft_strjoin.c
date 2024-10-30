/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:48:37 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/19 12:02:55 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*newstr;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(newstr))
		return (NULL);
	i = 0;
	while (*s1)
	{
		newstr[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		newstr[i++] = *s2;
		s2++;
	}
	newstr[i] = 0;
	return (newstr);
}
