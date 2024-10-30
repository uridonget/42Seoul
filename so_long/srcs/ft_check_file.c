/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:48:47 by haejeong          #+#    #+#             */
/*   Updated: 2023/12/19 11:55:36 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_file(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (0);
	if ((file_name[len - 1] == 'r') && \
		(file_name[len - 2] == 'e') && \
		(file_name[len - 3] == 'b') && \
		(file_name[len - 4] == '.'))
		return (1);
	return (0);
}
