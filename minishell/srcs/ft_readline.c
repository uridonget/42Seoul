/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:28:12 by haejeong          #+#    #+#             */
/*   Updated: 2024/04/01 12:12:57 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	chk_line_complete(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			while (line[++i] != '\'')
			{
				if (line[i] == 0)
					return (1);
			}
		}
		else if (line[i] == '\"')
		{
			while (line[++i] != '\"')
			{
				if (line[i] == 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

char	*ft_readline(int *exit_code)
{
	char	*line;

	line = readline("minishell$ \001\033[s\002");
	if (line == NULL)
	{
		free(line);
		ft_putstr("\001\033[u\002exit\n", 1);
		exit(*exit_code);
	}
	if (chk_line_complete(line))
	{
		*exit_code = 258;
		add_history(line);
		free(line);
		ft_putstr("minishell: syntax error line not complete\n", 2);
		return (NULL);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	add_history(line);
	return (line);
}
