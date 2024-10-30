/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:43:44 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/16 10:43:58 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*lexer_general_pipe(t_token *cur, int ctype, char input)
{
	if (cur->index != 0)
	{
		cur->next = new_token(1);
		cur = cur->next;
	}
	cur->type = ctype;
	push_char(cur, input);
	cur->next = new_token(10);
	cur = cur->next;
	return (cur);
}

t_token	*lexer_general(t_token *cur, int *state, char input)
{
	int	ctype;

	ctype = get_type(input);
	if (ctype == CHAR)
	{
		cur->type = CHAR;
		push_char(cur, input);
	}
	else if (ctype == PIPE)
		cur = lexer_general_pipe(cur, ctype, input);
	else
	{
		*state = get_status(ctype);
		if (cur->index != 0)
		{
			cur->next = new_token(10);
			cur = cur->next;
		}
		cur->type = ctype;
		if (ctype != QOUTE && ctype != DQOUTE)
			push_char(cur, input);
	}
	return (cur);
}

t_token	*lexer_qoute(t_token *cur, int *state, char input)
{
	int	ctype;

	ctype = get_type(input);
	if (ctype == cur->type)
	{
		cur->next = new_token(10);
		cur = cur->next;
		*state = GENERAL;
	}
	else
		push_char(cur, input);
	return (cur);
}

t_token	*lexer_redirection(t_token *cur, int *state, char **input)
{
	int	ctype;

	ctype = get_type(**input);
	if (ctype == cur->type)
	{
		push_char(cur, **input);
		if (ctype == L)
			cur->type = LL;
		else
			cur->type = RR;
		cur->next = new_token(10);
		cur = cur->next;
		*state = GENERAL;
	}
	else
	{
		cur->next = new_token(10);
		cur = cur->next;
		*state = GENERAL;
		*input -= 1;
	}
	return (cur);
}

t_token	*lexer_space(t_token *cur, int *state, char **input)
{
	int	ctype;

	ctype = get_type(**input);
	if (ctype == CHAR_WHITESPACE || ctype == CHAR_TAB)
		push_char(cur, **input);
	else
	{
		cur->next = new_token(10);
		cur = cur->next;
		*state = GENERAL;
		*input -= 1;
	}
	return (cur);
}
