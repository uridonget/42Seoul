/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:34:17 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/21 19:53:45 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(t_list *save)
{
	int				i;
	unsigned char	*s;

	if (!(save) || !(save->str))
		return (-1);
	s = (unsigned char *)(save->str);
	i = save->nl;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*gnl_free(t_list **save)
{
	if (*save)
	{
		if ((*save)->str)
		{
			free((*save)->str);
			(*save)->str = 0;
		}
		free(*save);
		*save = 0;
	}
	return (0);
}

int	gnl_init(t_list **save, int fd)
{
	if ((BUFFER_SIZE <= 0) || (fd < 0))
		return (0);
	if (!(*save))
	{
		*save = (t_list *)malloc(sizeof(t_list));
		if (!(*save))
			return (0);
		(*save)->str = 0;
		(*save)->len = 0;
		(*save)->nl = 0;
	}
	return (1);
}

t_list	*gnl_strjoin(t_list **save, char *buf, int read_size)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = malloc(sizeof(char) * (((*save)->len) + read_size + 1));
	if (!(newstr))
		return (gnl_free(save));
	i = 0;
	j = 0;
	if (*save && (*save)->str)
	{
		while (j < (*save)->len)
			newstr[i++] = ((*save)->str)[j++];
		free((*save)->str);
	}
	j = 0;
	while (j <= read_size)
		newstr[i++] = (buf)[j++];
	(*save)->str = newstr;
	(*save)->len += read_size;
	(*save)->nl = ((*save)->len) - read_size;
	return (*save);
}
