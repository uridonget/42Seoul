/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:42:52 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/24 11:46:24 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	set_here_doc(t_vars *vars)
{
	int		temp;
	char	*line;
	size_t	limit_len;

	limit_len = ft_strlen(vars->limiter) + 1;
	temp = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (temp == -1)
		fail_exit("Error opening heredoc file");
	while (1)
	{
		line = get_next_line(0);
		if (!(line))
		{
			close(temp);
			unlink(".tmp");
			fail_exit("Error gnl");
		}
		if (ft_strncmp(line, vars->limiter, limit_len) == 0)
			break ;
		write(temp, line, ft_strlen(line));
		write(temp, "\n", 1);
		free(line);
	}
	free(line);
	close(temp);
}

void	here_doc(t_vars *vars)
{
	set_here_doc(vars);
	vars->infile = open(".tmp", O_RDONLY);
	if (vars->infile == -1)
	{
		unlink(".tmp");
		fail_exit("Error opening infile");
	}
}
