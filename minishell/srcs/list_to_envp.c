/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:01:51 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/15 18:24:32 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	cnt_envp(t_envp *my_envp)
{
	int	i;

	i = 0;
	while (my_envp)
	{
		i++;
		my_envp = my_envp->next;
	}
	return (i);
}

static char	*make_envp_line(char *key, char *value)
{
	char	*temp;
	char	*new;

	temp = ft_strjoin(key, "=");
	if (!(temp))
		exit(EXIT_FAILURE);
	new = ft_strjoin(temp, value);
	if (!(new))
		exit(EXIT_FAILURE);
	free(temp);
	return (new);
}

char	**list_to_envp(t_envp *my_envp)
{
	int		i;
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * (cnt_envp(my_envp) + 1));
	if (!(temp))
		exit(EXIT_FAILURE);
	i = 0;
	while (my_envp)
	{
		temp[i] = make_envp_line(my_envp->key, my_envp->value);
		i++;
		my_envp = my_envp->next;
	}
	temp[i] = 0;
	return (temp);
}
