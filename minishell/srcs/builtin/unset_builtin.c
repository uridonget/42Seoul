/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:28:22 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/16 11:10:23 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	int	check_valid(char *key)
{
	int	index;

	index = 0;
	if ((ft_isalpha(key[index]) != 1) && (key[index] != '_'))
		return (0);
	while (key[index] != 0)
	{
		if ((ft_isalnum(key[index]) != 1) && (key[index] != '_'))
			return (0);
		index += 1;
	}
	return (1);
}

static int	check_key(t_envp **my_envp, char *key, t_envp *temp)
{
	if (ft_strcmp(temp->key, key) == 0)
	{
		if (temp->prev == NULL)
		{
			*my_envp = temp->next;
			(*my_envp)->prev = NULL;
		}
		else
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
		}
		free(temp->key);
		free(temp->value);
		free(temp);
		return (0);
	}
	return (1);
}

static int	delete_envp(t_envp **my_envp, char *key)
{
	t_envp	*temp;

	if (ft_strcmp(key, "_") == 0)
		return (0);
	if (check_valid(key) != 1)
	{
		ft_putstr("unset: \'", 2);
		ft_putstr(key, 2);
		ft_putstr("\': not a valid identifier\n", 2);
		return (1);
	}
	temp = *my_envp;
	while (temp)
	{
		if (check_key(my_envp, key, temp) == 0)
			return (0);
		temp = temp->next;
	}
	return (0);
}

int	unset_builtin(t_envp **my_envp, t_stage *stage)
{
	int		i;
	char	**keys;
	int		res;

	keys = stage->cmd;
	i = 0;
	res = 0;
	while (keys[i])
	{
		if (delete_envp(my_envp, keys[i]) == 1)
			res = 1;
		i++;
	}
	return (res);
}
