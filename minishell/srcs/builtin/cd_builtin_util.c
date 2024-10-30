/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:59:12 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/01 12:33:10 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	*free_cmd_split(char **cmd_split)
{
	while (*cmd_split)
	{
		free(*cmd_split);
		cmd_split++;
	}
	return (NULL);
}

static t_path	*create_path_cd(char **cmd_split, t_envp *my_envp, char *cur)
{
	t_path	*path;
	char	**temp;

	path = 0;
	if (ft_strcmp(*cmd_split, "~") == 0)
	{
		cur = get_home(my_envp);
		if (!(cur))
			return (free_cmd_split(cmd_split));
		add_home_to_path(cur, &path);
		free(*cmd_split);
		cmd_split++;
	}
	else
	{
		cur = getcwd(0, 0);
		temp = ft_split(cur, '/');
		if (!(cur) || !(temp))
			exit(EXIT_FAILURE);
		add_cmd_to_path(temp, &path);
		free(temp);
	}
	free(cur);
	add_cmd_to_path(cmd_split, &path);
	return (path);
}

char	*get_oldpwd(t_envp *my_envp)
{
	char	*res;

	while (my_envp != 0)
	{
		if (ft_strcmp(my_envp->key, "OLDPWD") == 0)
			break ;
		my_envp = my_envp->next;
	}
	if (my_envp == 0)
	{
		ft_putstr("minishell: cd: OLDPWD not set\n", 2);
		return (0);
	}
	res = ft_strdup(my_envp->value);
	if (res == 0)
		exit(EXIT_FAILURE);
	return (res);
}

t_path	*create_path_minus(t_envp *my_envp)
{
	t_path	*path;
	char	*cur;
	char	**oldpwd_split;

	path = 0;
	cur = get_oldpwd(my_envp);
	if (cur == 0)
		return (NULL);
	ft_putstr(cur, 1);
	ft_putstr("\n", 1);
	oldpwd_split = ft_split(cur, '/');
	if (oldpwd_split == NULL)
		exit(EXIT_FAILURE);
	add_cmd_to_path(oldpwd_split, &path);
	free(cur);
	free(oldpwd_split);
	return (path);
}

char	*get_relative_path_cd(char *cmd, t_envp *my_envp)
{
	char	**cmd_split;
	char	*connected_path;
	char	*res;
	t_path	*path;

	cmd_split = ft_split(cmd, '/');
	if (!(cmd_split))
		exit(EXIT_FAILURE);
	if (ft_strcmp(*cmd_split, "-") == 0 && ft_strslen(cmd_split) == 1)
	{
		path = create_path_minus(my_envp);
		if (!(path))
			return (free_strs(cmd_split));
		free(*cmd_split);
	}
	else
		path = create_path_cd(cmd_split, my_envp, 0);
	free(cmd_split);
	connected_path = connect_path(path);
	free_path(path);
	res = ft_strjoin("/", connected_path);
	if (!(res))
		exit(EXIT_FAILURE);
	free(connected_path);
	return (res);
}
