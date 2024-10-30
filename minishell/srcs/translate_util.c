/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:37:53 by sangyhan          #+#    #+#             */
/*   Updated: 2024/03/15 18:38:49 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_envp_value(char *start, t_envp *envp)
{
	int		value_len;
	char	*value;

	value_len = 1;
	while (ft_isalnum(start[value_len]) == 1 || start[value_len] == '_')
		value_len += 1;
	value = ft_substr(start, 1, value_len - 1);
	if (value == 0)
		exit(1);
	while (envp != 0)
	{
		if (ft_strcmp(envp->key, value) == 0)
			break ;
		envp = envp->next;
	}
	free(value);
	if (envp == 0)
		return (0);
	else
		return (envp->value);
}

char	*get_front(t_token *token, char *start, t_envp *envp)
{
	char	*res;
	char	*temp;
	char	*value;

	value = get_envp_value(start, envp);
	res = ft_substr(token->value, 0, (int)(start - token->value));
	if (res == 0)
		exit(1);
	if (value != 0)
	{
		temp = res;
		res = ft_strjoin(temp, value);
		if (res == 0)
			exit(1);
		free(temp);
	}
	return (res);
}

char	*get_tail(char *start, int key_len, char *res)
{
	char	*tail;
	char	*temp;

	tail = ft_substr(start + key_len, 0, ft_strlen(start + key_len));
	if (tail == 0)
		exit(1);
	temp = res;
	res = ft_strjoin(temp, tail);
	if (res == 0)
		exit(1);
	free(temp);
	free(tail);
	return (res);
}
