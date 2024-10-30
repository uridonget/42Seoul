/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:25:57 by sangyhan          #+#    #+#             */
/*   Updated: 2024/04/01 12:17:12 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_type(enum e_token type)
{
	if (type == CHAR || type == DQOUTE || type == QOUTE)
		return (0);
	else
		return (1);
}

t_token	*merge_str(t_token *token)
{
	t_token	*res;
	t_token	*temp;
	char	*new_str;

	res = token;
	while (token->type != CHAR_NULL)
	{
		if (check_type(token->type) == 0)
		{
			if (check_type(token->next->type) == 0)
			{
				temp = token->next;
				new_str = ft_strjoin(token->value, temp->value);
				if (new_str == 0)
					exit(1);
				free(temp->value);
				temp->value = new_str;
				res = del_token(res, token);
				token = temp;
				continue ;
			}
		}
		token = token->next;
	}
	return (res);
}

t_token	*del_null(t_token *token)
{
	t_token	*res;
	t_token	*temp;

	res = token;
	while (token->type != CHAR_NULL)
	{
		if (token->type == CHAR)
		{
			if (ft_strlen(token->value) == 0)
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

t_stage	*parse(char *input, t_envp *envp, int *exit_code)
{
	t_token	*token;
	t_stage	*res;

	token = lexer(input);
	if (check_syntex_err(token) == 1)
	{
		free_token(token);
		*exit_code = 258;
		free(input);
		return (0);
	}
	translate_value(token, envp, *exit_code);
	token = del_null(token);
	token = merge_str(token);
	res = get_redirection(token);
	token = del_redierction(token);
	token = del_space(token);
	token = echo_process(token);
	get_cmd(token, res);
	free_token(token);
	free(input);
	return (res);
}
