/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:18:47 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/11 14:19:01 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	int				flag;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	flag = 0;
	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (flag != 0 || index + 1 == n)
			break ;
		flag = temp_s1[index] - temp_s2[index];
		index++;
	}
	if (flag == 0)
		flag = temp_s1[index] - temp_s2[index];
	return (flag);
}
