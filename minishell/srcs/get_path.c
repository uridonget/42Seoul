/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:10:38 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/21 15:49:15 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*find_valid_path(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*temp;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin("/", cmd);
		temp = path;
		path = ft_strjoin(paths[i], temp);
		free(temp);
		if (access(path, F_OK) != -1)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_path(t_envp *my_envp, char **cmd)
{
	char	**paths;
	char	*path;
	char	*path_value;

	if (**cmd == '/')
		path = get_absolute_path(*cmd, my_envp);
	else
		path = get_relative_path(*cmd, my_envp);
	if (access(path, F_OK) == 0)
		return (path);
	free(path);
	if (*cmd && (**cmd == 0))
		return (0);
	path_value = get_envp_value("$PATH", my_envp);
	if (path_value != 0)
	{
		paths = ft_split(path_value, ':');
		if (!(paths))
			exit(EXIT_FAILURE);
		path = find_valid_path(paths, *cmd);
		free_strs(paths);
		return (path);
	}
	return (NULL);
}
