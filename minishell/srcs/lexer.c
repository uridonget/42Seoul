/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:25:04 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/16 10:48:33 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	lexer_add_null(t_token *cur)
{
	if (cur->index != 0)
	{
		cur->next = new_token(1);
		cur = cur->next;
	}
	cur->type = CHAR_NULL;
}

t_token	*lexer(char *input)
{
	int		state;
	t_token	*res;
	t_token	*cur;

	state = GENERAL;
	res = new_token(10);
	cur = res;
	while (*input != 0)
	{
		if (state == GENERAL)
			cur = lexer_general(cur, &state, *input);
		else if (state == STATE_QOUTE || state == STATE_DQOUTE)
			cur = lexer_qoute(cur, &state, *input);
		else if (state == STATE_L || state == STATE_R)
			cur = lexer_redirection(cur, &state, &input);
		else
			cur = lexer_space(cur, &state, &input);
		input += 1;
	}
	lexer_add_null(cur);
	return (res);
}
