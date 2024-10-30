/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:54:34 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/15 15:09:31 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <errno.h>

int	pwd_builtin(void)
{
	char	*path;

	path = getcwd(0, 0);
	if (path == 0)
	{
		strerror(errno);
		return (1);
	}
	ft_putstr(path, 1);
	ft_putchar('\n', 1);
	free(path);
	return (0);
}
