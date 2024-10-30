/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:48:24 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/21 14:40:55 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*del_token(t_token *root, t_token *target)
{
	t_token	*res;
	t_token	*temp;

	if (root == 0 || target == 0)
		return (root);
	if (root == target)
	{
		res = root->next;
		free(root->value);
		free(root);
		return (res);
	}
	res = root;
	while (root->next != target && root != 0)
		root = root->next;
	if (root != 0)
	{
		temp = root->next;
		root->next = root->next->next;
		free(temp->value);
		free(temp);
	}
	return (res);
}

static t_token	*del_node(t_token **token, t_token *root)
{
	t_token	*temp;

	temp = (*token)->next;
	root = del_token(root, *token);
	*token = temp;
	return (root);
}

t_token	*del_redierction(t_token *token)
{
	t_token	*res;

	res = token;
	while (token->type != CHAR_NULL)
	{
		if (token->type == L || token->type == LL
			|| token->type == R || token->type == RR)
		{
			res = del_node(&token, res);
			if (token->type == CHAR_WHITESPACE || token->type == CHAR_TAB)
				res = del_node(&token, res);
			if (token->type == CHAR || token->type == DQOUTE
				|| token->type == QOUTE)
				res = del_node(&token, res);
		}
		else
			token = token->next;
	}
	return (res);
}
