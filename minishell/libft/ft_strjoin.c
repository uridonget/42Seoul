/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:48:37 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/14 18:01:31 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*newstr;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(newstr))
		return (0);
	i = 0;
	while (s1 && *s1)
	{
		newstr[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		newstr[i++] = *s2;
		s2++;
	}
	newstr[i] = 0;
	return (newstr);
}
