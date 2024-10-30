/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:15:53 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/13 12:34:24 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*res;
	char	comp;

	comp = (char)c;
	res = (char *)s;
	while (*res != 0)
	{
		if (*res == comp)
			break ;
		res++;
	}
	if (*res != comp)
		return (0);
	return (res);
}
