/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stages.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:18:38 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 16:44:14 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	free_redirections(t_redirection *input)
{
	t_redirection	*temp;

	while (input)
	{
		free(input->filename);
		input->filename = 0;
		temp = input->next;
		free(input);
		input = temp;
	}
}

void	*free_strs(char **strs)
{
	int	i;

	if (strs == NULL)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

void	close_pipe(t_stage *stage)
{
	if ((stage->pipe)[0] != -1)
	{
		close((stage->pipe)[0]);
		(stage->pipe)[0] = -1;
	}
	if ((stage->pipe)[1] != -1)
	{
		close((stage->pipe)[1]);
		(stage->pipe)[1] = -1;
	}
}

void	close_all_pipe(t_stage *stage)
{
	while (stage && stage->prev)
		stage = stage->prev;
	while (stage)
	{
		if (stage->in_fd != -1)
			close(stage->in_fd);
		if (stage->out_fd != -1)
			close(stage->out_fd);
		close_pipe(stage);
		stage = stage->next;
	}
}

void	free_stages(t_stage *stage)
{
	t_stage	*temp;

	close_all_pipe(stage);
	while (stage)
	{
		free_strs(stage->cmd);
		if (stage->heredoc_name)
		{
			unlink(stage->heredoc_name);
			free(stage->heredoc_name);
		}
		free_redirections(stage->input);
		if (stage->cmd_path)
			free(stage->cmd_path);
		temp = stage->next;
		free(stage);
		stage = temp;
	}
}
