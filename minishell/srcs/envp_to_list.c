/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:42:03 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/26 11:20:51 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_envp	*new_envp(char *env)
{
	t_envp	*new;
	char	*equal_idx;

	if (env == 0)
		return (NULL);
	equal_idx = ft_strchr(env, '=');
	if (equal_idx == 0)
	{
		return (NULL);
	}
	new = (t_envp *)malloc(sizeof(t_envp));
	if (!(new))
		exit(EXIT_FAILURE);
	new->key = ft_substr(env, 0, (size_t)(equal_idx - env));
	if (!(new->key))
		exit(EXIT_FAILURE);
	new->value = ft_substr(equal_idx + 1, 0, ft_strlen(equal_idx));
	if (!(new->value))
		exit(EXIT_FAILURE);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_envp_back(t_envp **head, t_envp **new)
{
	t_envp	*last;

	if (!(head))
		return ;
	last = *head;
	if (!(*head))
		*head = *new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = *new;
		(*new)->prev = last;
	}
}

static void	shlvl_up(t_envp *my_envp)
{
	char	*new;
	int		shlvl;

	while (my_envp)
	{
		if (ft_strcmp(my_envp->key, "SHLVL") == 0)
			break ;
		my_envp = my_envp->next;
	}
	if (my_envp == NULL)
		return ;
	shlvl = ft_atoi(my_envp->value);
	shlvl += 1;
	new = ft_itoa(shlvl);
	if (!(new))
		exit(EXIT_FAILURE);
	free(my_envp->value);
	my_envp->value = new;
}

void	envp_to_list(t_envp **my_envp, char *envp[])
{
	t_envp	*new;

	*my_envp = NULL;
	while (*envp)
	{
		new = new_envp(*envp);
		if (!(new))
			return ;
		add_envp_back(my_envp, &new);
		envp++;
	}
	shlvl_up(*my_envp);
}
