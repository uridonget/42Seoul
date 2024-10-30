/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:16:50 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/16 14:50:16 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*now;

	now = (char *)s;
	res = 0;
	while (*now != 0)
	{
		if (*now == (char)c)
			res = now;
		now++;
	}
	if (*now == (char)c)
		res = now;
	return (res);
}
