/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_util_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghaechan <jeonghaechan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:09:30 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/31 09:35:44 by jeonghaecha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static size_t	get_total_len(t_path *path)
{
	size_t	total_len;

	total_len = 0;
	while (path)
	{
		total_len += ft_strlen(path->str) + 1;
		path = path->next;
	}
	return (total_len);
}

char	*connect_path(t_path *path)
{
	size_t	total_len;
	char	*res;

	if (path == NULL)
		return (NULL);
	total_len = get_total_len(path);
	res = (char *)malloc(total_len + 1);
	if (res == NULL)
		exit(EXIT_FAILURE);
	res[0] = 0;
	while (path)
	{
		ft_strcat(res, path->str);
		ft_strcat(res, "/");
		path = path->next;
	}
	res[total_len - 1] = 0;
	return (res);
}

void	add_home_to_path(char *home, t_path **path)
{
	t_path	*new;
	char	**home_split;
	char	**temp;

	home_split = ft_split(home, '/');
	if (!(home_split))
		exit(EXIT_FAILURE);
	temp = home_split;
	while (*home_split)
	{
		new = new_path(*home_split);
		if (!(new))
			exit(EXIT_FAILURE);
		add_path_back(path, new);
		home_split++;
	}
	free(temp);
}

void	add_cmd_to_path(char **cmd_split, t_path **path)
{
	t_path	*new;

	while (*cmd_split)
	{
		if (ft_strcmp(*cmd_split, "..") == 0)
		{
			free(*cmd_split);
			delete_last_path(path);
		}
		else if (ft_strcmp(*cmd_split, ".") == 0)
			free(*cmd_split);
		else
		{
			new = new_path(*cmd_split);
			if (!(new))
				exit(EXIT_FAILURE);
			add_path_back(path, new);
		}
		cmd_split++;
	}
}
