/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:00:10 by sangyhan          #+#    #+#             */
/*   Updated: 2023/10/19 14:39:50 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	flag;

	flag = 0;
	flag = ft_isalpha(c);
	if (flag == 0)
		flag = ft_isdigit(c);
	return (flag);
}
