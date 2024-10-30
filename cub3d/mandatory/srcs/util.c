/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:27:35 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/06 10:48:12 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

size_t	ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs && strs[len])
		len++;
	return (len);
}

void	ft_error(char *errMsg)
{
	ft_putstr_fd(errMsg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
