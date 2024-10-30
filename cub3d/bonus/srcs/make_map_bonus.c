/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:59:29 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 16:53:07 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	trim_lst_forward(t_museum *mu)
{
	char		*trim;
	t_mapLst	*node;

	while (mu->map.lst)
	{
		trim = ft_strtrim(mu->map.lst->line, " 	");
		if (ft_strlen(trim))
		{
			free(trim);
			break ;
		}
		free(trim);
		node = mu->map.lst->next;
		free(mu->map.lst->line);
		free(mu->map.lst);
		mu->map.lst = node;
		if (mu->map.lst)
			mu->map.lst->prev = NULL;
	}
}

static void	trim_lst_backward(t_museum *mu)
{
	char		*trim;
	t_mapLst	*temp;

	temp = mu->map.lst;
	while (temp && temp->next)
		temp = temp->next;
	while (temp)
	{
		trim = ft_strtrim(temp->line, " 	");
		if (ft_strlen(trim))
		{
			free(trim);
			break ;
		}
		free(trim);
		temp = temp->prev;
		free(temp->next->line);
		free(temp->next);
		if (temp)
			temp->next = NULL;
	}
}

static void	get_size_of_map(t_museum *mu)
{
	t_mapLst	*temp;

	temp = mu->map.lst;
	while (temp)
	{
		if (ft_strlen(temp->line) > mu->map.width)
			mu->map.width = ft_strlen(temp->line);
		mu->map.height += 1;
		temp = temp->next;
	}
	if (mu->map.width < 3 || mu->map.height < 3)
		ft_error("Error\nInvalid Map File");
}

void	make_map(t_museum *mu)
{
	t_mapLst	*node;
	int			i;
	int			j;

	trim_lst_forward(mu);
	trim_lst_backward(mu);
	get_size_of_map(mu);
	make_base(mu);
	i = 1;
	while (mu->map.lst)
	{
		node = mu->map.lst->next;
		j = 0;
		while (mu->map.lst->line[j])
		{
			mu->map.map[i][j + 1] = mu->map.lst->line[j];
			j++;
		}
		i++;
		free(mu->map.lst->line);
		free(mu->map.lst);
		mu->map.lst = node;
	}
}
