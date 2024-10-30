/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:34:21 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/25 11:11:51 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	cmd_malloc(t_vars *vars)
{	
	vars->cmd = (char ***)ft_calloc(sizeof(char **), (vars->cmd_num + 1));
	if (!(vars->cmd))
	{
		close_fd(vars);
		fail_exit("Error malloc");
	}
	vars->cmd_path = (char **)ft_calloc(sizeof(char *), (vars->cmd_num + 1));
	if (!(vars->cmd_path))
	{
		close_fd(vars);
		free(vars->cmd);
		fail_exit("Error malloc");
	}
}

static void	fail_exit_path(t_vars *v, char *p, char **env_p, char *msg)
{
	free(p);
	free_double(env_p);
	free_close(v);
	fail_exit(msg);
}

static void	get_cmd_path(t_vars *vars, char *path, char **env_paths, int n)
{
	int		i;
	char	*chk_path;

	i = -1;
	while (env_paths[++i])
	{
		chk_path = ft_strjoin(env_paths[i], path);
		if (!(chk_path))
			fail_exit_path(vars, path, env_paths, "Error making chk_path");
		if (access(chk_path, X_OK) != -1)
		{
			vars->cmd_path[n] = chk_path;
			free(path);
			return ;
		}
		free(chk_path);
	}
	fail_exit_path(vars, path, env_paths, "Error command not found");
}

static void	chk_path(t_vars *vars, char **env_paths, char *av[])
{
	int		i;
	char	*path;

	i = 0;
	while (i < vars->cmd_num)
	{
		vars->cmd[i] = ft_split(av[2 + i], ' ');
		if (!(vars->cmd[i]))
		{
			free_double(env_paths);
			free_close(vars);
			fail_exit("Error spliting cmd and flag");
		}
		path = ft_strjoin("/", *(vars->cmd[i]));
		if (!(path))
		{
			free_double(env_paths);
			free_close(vars);
			fail_exit("Error making /cmd");
		}
		get_cmd_path(vars, path, env_paths, i);
		i++;
	}
}

void	set_path(t_vars *vars, char *av[], char *envp[])
{
	char	*path;
	char	**env_paths;
	int		i;

	cmd_malloc(vars);
	i = 0;
	while (envp[i])
	{
		if (!(ft_strncmp(envp[i], "PATH=", 5)))
		{
			path = (envp[i] + 5);
			break ;
		}
		i++;
	}
	env_paths = ft_split(path, ':');
	if (!(env_paths))
	{
		free_close(vars);
		fail_exit("Error spliting path");
	}
	chk_path(vars, env_paths, av);
	free_double(env_paths);
}
