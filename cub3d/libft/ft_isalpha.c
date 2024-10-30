/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:57:29 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/15 10:57:30 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	flag;

	flag = 0;
	if (c >= 'a' && c <= 'z')
		flag = 1;
	else if (c >= 'A' && c <= 'Z')
		flag = 1;
	return (flag);
}
