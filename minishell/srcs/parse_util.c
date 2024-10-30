/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:20:33 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/25 20:09:42 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_cmd(t_token *token)
{
	int	res;

	res = 0;
	while (token->type != CHAR_NULL)
	{
		if (token->type == CHAR || token->type == DQOUTE || token->type == QOUTE
			|| token->type == CHAR_WHITESPACE || token->type == CHAR_TAB)
			res += 1;
		else if (token->type == PIPE)
			break ;
		token = token->next;
	}
	return (res);
}

t_stage	*new_stage(void)
{
	t_stage	*res;

	res = malloc(sizeof(t_stage));
	if (res == 0)
		exit(EXIT_FAILURE);
	res->cmd = NULL;
	res->cmd_path = NULL;
	res->in_fd = -1;
	res->out_fd = -1;
	res->stdin_temp = -1;
	res->stdout_temp = -1;
	if (pipe(res->pipe) < 0)
		exit(EXIT_FAILURE);
	res->pid = -1;
	res->heredoc_name = NULL;
	res->input = NULL;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	get_cmd(t_token *token, t_stage *res)
{
	int		index;

	index = 0;
	res->cmd = ft_calloc(sizeof(char *), (count_cmd(token) + 1));
	if (res->cmd == 0)
		exit(1);
	while (token != 0 && token->type != CHAR_NULL)
	{
		if (token->type == PIPE)
		{
			res = res->next;
			res->cmd = ft_calloc(sizeof(char *), (count_cmd(token->next) + 1));
			if (res->cmd == 0)
				exit(1);
			index = 0;
		}
		else
		{
			(res->cmd)[index] = ft_strdup(token->value);
			if ((res->cmd)[index] == 0)
				exit(1);
			index += 1;
		}
		token = token->next;
	}
}

t_token	*del_space(t_token *token)
{
	t_token	*res;
	t_token	*temp;

	res = token;
	while (token->type != CHAR_NULL)
	{
		if (token->type == CHAR_WHITESPACE || token->type == CHAR_TAB)
		{
			if (token->next->type == CHAR_WHITESPACE
				|| token->next->type == CHAR_TAB)
			{
				temp = token->next;
				res = del_token(res, token);
				token = temp;
			}
			else
				token = token->next;
		}
		else
			token = token->next;
	}
	return (res);
}
