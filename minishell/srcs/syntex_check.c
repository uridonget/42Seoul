/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntex_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:31:03 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/26 16:33:32 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	print_syntex_err(int type)
{
	if (type == PIPE)
		write(2, "minishell: syntax error near unexpected token `|'\n", 51);
	else if (type == L)
		write(2, "minishell: syntax error near unexpected token `<'\n", 51);
	else if (type == LL)
		write(2, "minishell: syntax error near unexpected token `<<'\n", 52);
	else if (type == R)
		write(2, "minishell: syntax error near unexpected token `>'\n", 51);
	else if (type == RR)
		write(2, "minishell: syntax error near unexpected token `>>'\n", 52);
	else if (type == CHAR_NULL)
		write(2, "minishell: syntax error: unexpected end of file\n", 49);
}

static int	check_syntex_err_redi(t_token **token)
{
	*token = (*token)->next;
	if ((*token)->type == CHAR_TAB || (*token)->type == CHAR_WHITESPACE)
		*token = (*token)->next;
	if ((*token)->type != CHAR && (*token)->type != DQOUTE
		&& (*token)->type != QOUTE)
	{
		print_syntex_err((*token)->type);
		return (1);
	}
	return (0);
}

static int	check_syntex_err_pipe(t_token **token)
{
	*token = (*token)->next;
	if ((*token)->type == CHAR_TAB || (*token)->type == CHAR_WHITESPACE)
		*token = (*token)->next;
	if ((*token)->type == CHAR_NULL || (*token)->type == PIPE)
	{
		print_syntex_err((*token)->type);
		return (1);
	}
	return (0);
}

int	check_syntex_err(t_token *token)
{
	while (token->type == CHAR_WHITESPACE || token->type == CHAR_TAB)
		token = token->next;
	if (token->type == PIPE)
	{
		print_syntex_err(token->type);
		return (1);
	}
	while (token->type != CHAR_NULL)
	{
		if (token->type == L || token->type == LL
			|| token->type == R || token->type == RR)
		{
			if (check_syntex_err_redi(&token) == 1)
				return (1);
			continue ;
		}
		else if (token->type == PIPE)
		{
			if (check_syntex_err_pipe(&token) == 1)
				return (1);
			continue ;
		}
		token = token->next;
	}
	return (0);
}
