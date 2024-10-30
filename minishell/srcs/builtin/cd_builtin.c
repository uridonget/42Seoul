/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:59:15 by sangyhan          #+#    #+#             */
/*   Updated: 2024/04/01 12:25:55 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	swap_pwd_value(t_envp *my_envp, char *path)
{
	free(my_envp->value);
	my_envp->value = ft_strdup(path);
	if (my_envp->value == 0)
		exit(EXIT_FAILURE);
	free(path);
}

static void	update_oldpwd(t_envp *my_envp, char *path)
{
	t_envp	*root;
	t_envp	*new;

	root = my_envp;
	while (my_envp != 0)
	{
		if (ft_strcmp(my_envp->key, "OLDPWD") == 0)
		{
			swap_pwd_value(my_envp, path);
			break ;
		}
		my_envp = my_envp->next;
	}
	if (my_envp == 0)
	{
		new = new_envp("OLDPWD=");
		swap_pwd_value(new, path);
		export_envp(&root, &new);
	}
}

static void	update_pwd(t_envp *my_envp, char *path, char *pwd)
{
	t_envp	*root;

	root = my_envp;
	update_oldpwd(root, pwd);
	while (my_envp != 0)
	{
		if (ft_strcmp(my_envp->key, "PWD") == 0)
		{
			free(my_envp->value);
			my_envp->value = ft_strdup(path);
			if (my_envp->value == 0)
				exit(1);
			break ;
		}
		my_envp = my_envp->next;
	}
}

char	*get_home(t_envp *my_envp)
{
	char	*res;

	while (my_envp != 0)
	{
		if (ft_strcmp(my_envp->key, "HOME") == 0)
			break ;
		my_envp = my_envp->next;
	}
	if (my_envp == 0)
	{
		ft_putstr("minishell: cd: HOME not set\n", 2);
		return (0);
	}
	res = ft_strdup(my_envp->value);
	if (res == 0)
		exit(1);
	return (res);
}

int	cd_builtin(t_envp *my_envp, char *dir)
{
	char	*dst;
	char	*pwd;

	if (dir == NULL)
	{
		dst = get_home(my_envp);
		if (dst == NULL)
			return (1);
	}
	else if (*dir == '/')
		dst = get_absolute_path(dir, my_envp);
	else
		dst = get_relative_path_cd(dir, my_envp);
	if (dst == NULL)
		exit(EXIT_FAILURE);
	pwd = getcwd(0, 0);
	if (!(pwd))
		exit(EXIT_FAILURE);
	if (chdir(dst) == -1)
		return (chdir_err(pwd, dst));
	else
		update_pwd(my_envp, dst, pwd);
	free(dst);
	return (0);
}
