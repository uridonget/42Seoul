/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:00:21 by haejeong          #+#    #+#             */
/*   Updated: 2024/03/22 13:51:27 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern int	g_status;

void	check_heredoc_number(t_stage *stage)
{
	t_redirection	*input;
	int				cnt;

	cnt = 0;
	while (stage)
	{
		input = stage->input;
		while (input)
		{
			if (input->type == LL)
				cnt++;
			input = input->next;
		}
		stage = stage->next;
	}
	if (cnt > 16)
	{
		ft_putstr("minishell: maximum here-document count exceeded\n", 2);
		exit(2);
	}
}

static int	heredoc(char *limiter, char *filename)
{
	int		temp;
	char	*line;

	temp = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (temp < 0)
		return (1);
	while (INFINITE)
	{
		line = readline("> ");
		if ((line == NULL) || (ft_strcmp(line, limiter) == 0))
			break ;
		write(temp, line, ft_strlen(line));
		write(temp, "\n", 1);
		free(line);
	}
	close(temp);
	free(line);
	return (0);
}

static int	make_tmp_file(t_stage *stage)
{
	t_redirection	*input;

	while (stage)
	{
		input = stage->input;
		while (input)
		{
			if (input->type == LL)
			{
				if (heredoc(input->filename, stage->heredoc_name))
				{
					unlink(input->filename);
					return (1);
				}
			}
			input = input->next;
		}
		stage = stage->next;
	}
	return (0);
}

void	name_tmpfile(t_stage *stage)
{
	char			*num;
	int				n;
	t_redirection	*input;

	n = 0;
	while (stage)
	{
		input = stage->input;
		while (input != 0)
		{
			if (input->type == LL)
			{
				num = ft_itoa(n++);
				if (!(num))
					exit(EXIT_FAILURE);
				stage->heredoc_name = ft_strjoin(".", num);
				if (!(stage->heredoc_name))
					exit(EXIT_FAILURE);
				free(num);
				break ;
			}
			input = input->next;
		}
		stage = stage->next;
	}
}

void	process_heredoc(t_stage *stage)
{
	init_heredoc();
	if (make_tmp_file(stage))
	{
		while (stage)
		{
			if (stage->heredoc_name)
				unlink(stage->heredoc_name);
			stage = stage->next;
		}
		exit(1);
	}
	exit(0);
}
