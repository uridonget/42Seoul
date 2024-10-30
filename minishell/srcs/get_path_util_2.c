/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_util_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:28:53 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/15 18:26:47 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_path	*new_path(char *str)
{
	t_path	*new;

	new = (t_path *)malloc(sizeof(t_path));
	if (!(new))
		return (NULL);
	new->str = str;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_path_back(t_path **path, t_path *new)
{
	t_path	*last;

	if (!(*path))
	{
		*path = new;
		return ;
	}
	last = *path;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	delete_last_path(t_path **path)
{
	t_path	*cur;

	if ((!(path)) || (!(*path)))
		return ;
	cur = *path;
	while (cur->next != NULL)
		cur = cur->next;
	if (cur->prev == NULL)
	{
		free(cur->str);
		free(cur);
		*path = NULL;
		return ;
	}
	cur->prev->next = NULL;
	free(cur->str);
	free(cur);
}

void	free_path(t_path *path)
{
	t_path	*temp;

	while (path)
	{
		free(path->str);
		temp = path->next;
		free(path);
		path = temp;
	}
}
