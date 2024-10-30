/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:05:16 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/01 16:07:06 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	int				flag;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	flag = 0;
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (flag != 0)
			break ;
		flag = temp_s1[index] - temp_s2[index];
		index++;
	}
	if (flag == 0)
		flag = temp_s1[index] - temp_s2[index];
	return (flag);
}
