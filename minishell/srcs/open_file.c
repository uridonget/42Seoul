/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:54:47 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/21 15:01:40 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	open_infile(t_stage *stage, t_redirection *input)
{
	if (stage->in_fd != -1)
		close(stage->in_fd);
	if (input->type == L)
	{
		stage->in_fd = open(input->filename, O_RDONLY, 0644);
		if (stage->in_fd < 0)
		{
			ft_putstr("minishell: ", 2);
			ft_putstr(input->filename, 2);
			ft_putstr(": No such file or directory\n", 2);
			return (1);
		}
	}
	else
	{
		stage->in_fd = open(stage->heredoc_name, O_RDONLY, 0644);
		if (stage->in_fd < 0)
			return (1);
	}
	return (0);
}

static int	open_outfile(t_stage *stage, t_redirection *input)
{
	if (stage->out_fd != -1)
		close(stage->out_fd);
	if (input->type == R)
	{
		stage->out_fd = open(input->filename, \
		O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else
	{
		stage->out_fd = open(input->filename, \
		O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	if (stage->out_fd < 0)
	{
		if (input->filename == 0)
			ft_putstr("minishell: ambiguous redirect\n", 2);
		else
		{
			ft_putstr("minishell: ", 2);
			ft_putstr(input->filename, 2);
			ft_putstr(": No such file or directory\n", 2);
		}
		return (1);
	}
	return (0);
}

int	open_file(t_stage *stage)
{
	t_redirection	*temp;

	if (!(stage->input))
		return (0);
	temp = stage->input;
	while (temp)
	{
		if ((temp->type == L) || (temp->type == LL))
		{
			if (open_infile(stage, temp))
			{
				stage->in_fd = -1;
				return (1);
			}
		}
		else if (open_outfile(stage, temp))
		{
			stage->out_fd = -1;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
