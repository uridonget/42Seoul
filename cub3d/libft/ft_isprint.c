/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:55:22 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/15 10:55:29 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int	flag;

	flag = 0;
	if (c >= 32 && c <= 126)
		flag = 1;
	return (flag);
}
