/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:04:28 by sang              #+#    #+#             */
/*   Updated: 2023/10/12 14:44:50 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (fd < 0 || s == 0)
		return ;
	index = 0;
	while (s[index] != 0)
	{
		write(fd, &s[index], 1);
		index++;
	}
}
