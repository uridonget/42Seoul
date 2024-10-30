/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:48:33 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/21 15:44:09 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_redirection	*new_redirection(void)
{
	t_redirection	*res;

	res = malloc(sizeof(t_redirection));
	if (res == 0)
		exit(1);
	res->next = 0;
	res->filename = 0;
	return (res);
}

static void	get_filename(t_redirection *cur, t_token *token)
{
	cur->type = token->type;
	if (token->next->type == CHAR_WHITESPACE || token->next->type == CHAR_TAB)
		token = token->next;
	if (token->next->type == CHAR || token->next->type == DQOUTE
		|| token->next->type == QOUTE)
	{
		cur->filename = ft_strdup(token->next->value);
		if (cur->filename == 0)
			exit(EXIT_FAILURE);
	}
	else
		cur->filename = 0;
}

static void	push_redirection(t_redirection **list, t_token *token)
{
	t_redirection	*cur;

	if ((*list) == 0)
	{
		*list = new_redirection();
		cur = *list;
	}
	else
	{
		cur = *list;
		while (cur->next != 0)
			cur = cur->next;
		cur->next = new_redirection();
		cur = cur->next;
	}
	get_filename(cur, token);
}

t_stage	*get_redirection(t_token *token)
{
	t_stage	*root;
	t_stage	*res;

	res = new_stage();
	root = res;
	while (token != 0 && token->type != CHAR_NULL)
	{
		if (token->type == L || token->type == LL
			|| token->type == R || token->type == RR)
		{
			push_redirection(&(res->input), token);
			if (token->next->type == CHAR_WHITESPACE
				|| token->next->type == CHAR_TAB)
				token = token->next;
			token = token->next;
		}
		else if (token->type == PIPE)
		{
			res->next = new_stage();
			res->next->prev = res;
			res = res->next;
		}
		token = token->next;
	}
	return (root);
}
