/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:22:10 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/16 14:37:27 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*translate(t_token *token, char *start, t_envp *envp)
{
	int		key_len;
	int		value_len;
	char	*res;
	char	*res_pos;

	key_len = 1;
	while (ft_isalnum(start[key_len]) == 1 || start[key_len] == '_')
		key_len += 1;
	res = get_front(token, start, envp);
	if (*(start + key_len) != 0)
		res = get_tail(start, key_len, res);
	value_len = ft_strlen(get_envp_value(start, envp));
	res_pos = res + (int)(start - token->value) + value_len;
	free(token->value);
	token->value = res;
	return (res_pos);
}

static char	*get_front_status(t_token *token, char *start, int exit_code)
{
	char	*res;
	char	*temp;
	char	*value;

	value = ft_itoa(exit_code);
	if (value == 0)
		exit(1);
	res = ft_substr(token->value, 0, (int)(start - token->value));
	if (res == 0)
		exit(1);
	temp = res;
	res = ft_strjoin(temp, value);
	if (res == 0)
		exit(1);
	free(temp);
	free(value);
	return (res);
}

static char	*translate_state(t_token *token, char *start, int exit_code)
{
	int		key_len;
	int		value_len;
	char	*res;
	char	*res_pos;
	char	*temp;

	key_len = 2;
	res = get_front_status(token, start, exit_code);
	if (*(start + key_len) != 0)
		res = get_tail(start, key_len, res);
	temp = ft_itoa(exit_code);
	value_len = ft_strlen(temp);
	free(temp);
	res_pos = res + (int)(start - token->value) + value_len;
	free(token->value);
	token->value = res;
	return (res_pos);
}

void	translate_value(t_token *token, t_envp *envp, int exit_code)
{
	char	*cur;

	while (token->type != CHAR_NULL)
	{
		if (token->type == CHAR || token->type == DQOUTE)
		{
			cur = token->value;
			while (*cur != 0)
			{
				if (*cur == '$' && *(cur + 1) == '?')
					cur = translate_state(token, cur, exit_code);
				else if (*cur == '$' && (ft_isalpha(*(cur + 1)) == 1 \
				|| *(cur + 1) == '_'))
					cur = translate(token, cur, envp);
				else
					cur += 1;
			}
		}
		token = token->next;
	}
}
