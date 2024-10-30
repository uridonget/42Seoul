/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:14:24 by haejeong          #+#    #+#             */
/*   Updated: 2023/11/02 14:53:21 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_make_line(t_list **save, int idx)
{
	int		i;
	char	*line;

	line = (char *)malloc(sizeof(char) * (idx + 2));
	if (!(line))
		return (ft_free(save));
	i = 0;
	while (i <= idx)
	{
		line[i] = ((*save)->str)[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static t_list	*ft_make_save(t_list **save, int idx)
{
	int		i;
	char	*new_save;

	new_save = (char *)malloc(sizeof(char) * (((*save)->len) - idx + 1));
	if (!(new_save))
		return (ft_free(save));
	i = 0;
	while (((*save)->str)[idx + i + 1])
	{
		new_save[i] = ((*save)->str)[idx + i + 1];
		i++;
	}
	new_save[i] = 0;
	free((*save)->str);
	(*save)->str = new_save;
	(*save)->len -= (idx + 1);
	(*save)->nl = 0;
	return (*save);
}

static int	ft_read_line(int fd, char *buf, t_list **save)
{
	int	read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == -1)
	{
		ft_free(save);
		return (-1);
	}
	(buf)[read_size] = 0;
	return (read_size);
}

static char	*ft_read_end(t_list **save)
{
	char	*line;

	if (*((*save)->str) == 0)
		return (ft_free(save));
	else
	{
		line = (*save)->str;
		(*save)->str = 0;
		free(*save);
		*save = 0;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*save[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	char			*line;
	int				read_size;

	if (ft_init(&(save[fd]), fd) == 0)
		return (0);
	while (ft_find_nl(save[fd]) == -1)
	{
		read_size = ft_read_line(fd, buf, &(save[fd]));
		if (read_size == -1)
			return (0);
		if (!(ft_strjoin(&(save[fd]), buf, read_size)))
			return (0);
		if (read_size == 0)
			return (ft_read_end(&(save[fd])));
	}
	line = ft_make_line(&(save[fd]), ft_find_nl(save[fd]));
	if (line)
		save[fd] = ft_make_save(&(save[fd]), ft_find_nl(save[fd]));
	return (line);
}
