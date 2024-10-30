/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:19:11 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/07 09:17:25 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	if (!s)
		return (0);
	while (s[res] != 0)
	{
		res++;
	}
	return (res);
}
