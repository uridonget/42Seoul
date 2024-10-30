/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:41:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 14:56:14 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_envp(t_envp **my_envp, t_envp **new)
{
	t_envp	*temp;

	temp = *my_envp;
	if (ft_strcmp((*new)->key, "_") == 0)
	{
		free((*new)->key);
		free((*new)->value);
		free(*new);
		return ;
	}
	while (temp)
	{
		if (ft_strcmp(temp->key, (*new)->key) == 0)
		{
			free(temp->value);
			temp->value = (*new)->value;
			free((*new)->key);
			free(*new);
			return ;
		}
		temp = temp->next;
	}
	add_envp_back(my_envp, new);
}

static	int	check_valid(t_envp *new)
{
	int	index;
	int	flag;

	flag = 1;
	index = 0;
	if (ft_isalpha(new->key[index]) != 1 && new->key[index] != '_')
		flag = 0;
	while (new->key[index] != 0 && flag == 1)
	{
		if (ft_isalnum(new->key[index]) != 1 && new->key[index] != '_')
			flag = 0;
		index += 1;
	}
	if (flag == 0)
	{
		ft_putstr("export: \'", 2);
		ft_putstr(new->key, 2);
		ft_putstr("\': not a valid identifier\n", 2);
		free(new->key);
		free(new->value);
		free(new);
	}
	return (flag);
}

static int	print_env(t_envp *my_envp, char **cmd)
{
	if (cmd[1])
		return (0);
	while (my_envp)
	{
		ft_putstr("export ", 1);
		ft_putstr(my_envp->key, 1);
		ft_putchar('=', 1);
		ft_putstr(my_envp->value, 1);
		ft_putchar('\n', 1);
		my_envp = my_envp->next;
	}
	return (1);
}

static	int	check_valid_key(char *key)
{
	int	index;
	int	flag;

	flag = 0;
	index = 0;
	if (ft_isalpha(key[index]) != 1 && key[index] != '_')
		flag = 1;
	while (key[index] != 0 && flag == 0)
	{
		if (ft_isalnum(key[index]) != 1 && key[index] != '_')
			flag = 1;
		index += 1;
	}
	if (flag == 1)
	{
		ft_putstr("export: \'", 2);
		ft_putstr(key, 2);
		ft_putstr("\': not a valid identifier\n", 2);
	}
	return (flag);
}

int	export_builtin(t_envp *my_envp, char **cmd)
{
	t_envp	*new;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (print_env(my_envp, cmd))
		return (0);
	while (cmd[i])
	{
		new = new_envp(cmd[i]);
		if (new == NULL)
		{
			if (check_valid_key(cmd[i]) == 1)
				flag = 1;
		}
		else if (check_valid(new) != 1)
			flag = 1;
		else
			export_envp(&my_envp, &new);
		i++;
	}
	return (flag);
}
