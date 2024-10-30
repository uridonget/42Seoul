/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:45:50 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/16 11:27:42 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_token	*echo_process_space(t_token *token, t_token **res,
								int first_flag)
{
	t_token	*temp;

	if (first_flag == 0 || token->next->type == PIPE
		|| token->next->type == CHAR_NULL)
	{
		temp = token->next;
		*res = del_token(*res, token);
		token = temp;
	}
	else
	{
		free(token->value);
		token->value = ft_strdup(" ");
		if (token->value == 0)
			exit(1);
		token = token->next;
	}
	return (token);
}

static t_token	*echo_process_pipe(t_token *token,
						int *first_flag, int *echo_flag)
{
	int	index;

	if (*echo_flag == 0)
	{
		if (ft_strcmp(token->value, "echo") == 0)
			*echo_flag = 1;
		else
			*echo_flag = -1;
	}
	else if (*echo_flag == 1 && *first_flag == 0)
	{
		if ((token->value)[0] == '-')
		{
			index = 1;
			while ((token->value)[index] == 'n')
				index += 1;
			if (index == 1 || (token->value)[index] != 0)
				*first_flag = 1;
		}
		else
			*first_flag = 1;
	}
	token = token->next;
	return (token);
}

t_token	*echo_process(t_token *token)
{
	int		echo_flag;
	int		first_flag;
	t_token	*res;

	res = token;
	echo_flag = 0;
	first_flag = 0;
	while (token->type != CHAR_NULL)
	{
		if (token->type == CHAR_WHITESPACE || token->type == CHAR_TAB)
			token = echo_process_space(token, &res, first_flag);
		else if (token->type == CHAR || token->type == DQOUTE
			|| token->type == QOUTE)
			token = echo_process_pipe(token, &first_flag, &echo_flag);
		else if (token->type == PIPE)
		{
			echo_flag = 0;
			first_flag = 0;
			token = token->next;
		}
	}
	return (res);
}
