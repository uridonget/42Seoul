/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_map_list_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:48:27 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/11 12:35:22 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	map_lst_add_back(t_mapLst **lst, t_mapLst *new)
{
	t_mapLst	*last;

	last = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (last->next)
			last = last->next;
		new->prev = last;
		last->next = new;
	}
}

t_mapLst	*map_lst_new(char *content)
{
	t_mapLst	*newlst;

	newlst = (t_mapLst *)malloc(sizeof(t_mapLst));
	if (!(newlst))
		exit(EXIT_FAILURE);
	newlst->line = content;
	newlst->prev = NULL;
	newlst->next = NULL;
	return (newlst);
}
