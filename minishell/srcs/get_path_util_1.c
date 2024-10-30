/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_util_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 08:17:57 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/22 12:50:05 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_absolute_path(char *cmd, t_envp *my_envp)
{
	char	**cmd_split;
	char	**temp;
	char	*connected_path;
	char	*res;
	t_path	*path;

	cmd_split = ft_split(cmd, '/');
	if (!(cmd_split))
		exit(EXIT_FAILURE);
	temp = cmd_split;
	path = 0;
	if (ft_strcmp(*cmd_split, "~") == 0)
	{
		add_home_to_path(get_home(my_envp), &path);
		cmd_split++;
	}
	add_cmd_to_path(cmd_split, &path);
	free(temp);
	connected_path = connect_path(path);
	free_path(path);
	res = ft_strjoin("/", connected_path);
	if (!(res))
		exit(EXIT_FAILURE);
	free(connected_path);
	return (res);
}

static t_path	*create_path(char **cmd_split, t_envp *my_envp)
{
	t_path	*path;
	char	*cur;
	char	**temp;

	path = 0;
	if (ft_strcmp(*cmd_split, "~") == 0)
	{
		cur = get_home(my_envp);
		add_home_to_path(cur, &path);
		free(cur);
		free(*cmd_split);
		cmd_split++;
	}
	if (!(ft_strcmp(*cmd_split, ".")) || !(get_envp_value("$PATH", my_envp)))
	{
		cur = getcwd(0, 0);
		temp = ft_split(cur, '/');
		if (!(cur) || !(temp))
			exit(EXIT_FAILURE);
		free(cur);
		add_cmd_to_path(temp, &path);
		free(temp);
	}
	add_cmd_to_path(cmd_split, &path);
	return (path);
}

char	*get_relative_path(char *cmd, t_envp *my_envp)
{
	char	**cmd_split;
	char	*connected_path;
	char	*res;
	t_path	*path;

	if (ft_strlen(cmd) == 0)
		return (NULL);
	cmd_split = ft_split(cmd, '/');
	if (!(cmd_split))
		exit(EXIT_FAILURE);
	path = create_path(cmd_split, my_envp);
	free(cmd_split);
	connected_path = connect_path(path);
	free_path(path);
	res = ft_strjoin("/", connected_path);
	if (!(res))
		exit(EXIT_FAILURE);
	free(connected_path);
	return (res);
}
