/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:28:22 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/16 10:26:22 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_type(char c)
{
	if (c == ' ')
		return (CHAR_WHITESPACE);
	else if (c == '\t')
		return (CHAR_TAB);
	else if (c == '|')
		return (PIPE);
	else if (c == '\'')
		return (QOUTE);
	else if (c == '\"')
		return (DQOUTE);
	else if (c == '<')
		return (L);
	else if (c == '>')
		return (R);
	else if (c == '\0')
		return (CHAR_NULL);
	else
		return (CHAR);
}

int	get_status(int type)
{
	if (type == CHAR_WHITESPACE)
		return (STATE_SPACE);
	else if (type == CHAR_TAB)
		return (STATE_SPACE);
	else if (type == QOUTE)
		return (STATE_QOUTE);
	else if (type == DQOUTE)
		return (STATE_DQOUTE);
	else if (type == L)
		return (STATE_L);
	else if (type == R)
		return (STATE_R);
	else
		return (GENERAL);
}

t_token	*new_token(int size)
{
	t_token	*res;

	res = malloc(sizeof(t_token));
	if (res == 0)
		exit(1);
	res->str_len = size;
	res->value = ft_calloc(size + 1, sizeof(char));
	res->next = 0;
	res->index = 0;
	return (res);
}

void	push_char(t_token *token, char c)
{
	char	*temp;

	if (token->index >= token->str_len)
	{
		temp = ft_calloc(token->str_len * 2 + 1, sizeof(char));
		if (temp == 0)
			exit(1);
		ft_strlcpy(temp, token->value, token->index + 1);
		token->str_len *= 2;
		free(token->value);
		token->value = temp;
	}
	(token->value)[token->index] = c;
	token->index += 1;
}

void	free_token(t_token *token)
{
	t_token	*cur;
	t_token	*past;

	cur = token;
	while (cur != 0)
	{
		free(cur->value);
		past = cur;
		cur = cur->next;
		free(past);
	}
}
