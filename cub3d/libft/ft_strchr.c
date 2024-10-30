/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:15:53 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/12 14:47:46 by sangyhan         ###   ########.fr       */
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
