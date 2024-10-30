/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:31:49 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/03 10:25:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_count(const char *str, char c)
{
	int		index;
	int		count;
	int		flag;

	flag = 1;
	count = 0;
	index = 0;
	while (str[index] != 0)
	{
		if (str[index] != c)
		{	
			if (flag == 1)
			{	
				count++;
				flag = 0;
			}
		}
		else
			flag = 1;
		index++;
	}
	return (count);
}

static int	ft_make_word(char **res, const char *str, int *now, char c)
{
	int		index;
	int		count;

	while (str[*now] == c)
		(*now)++;
	count = 0;
	while (str[*now + count] != c && str[*now + count] != 0)
		count++;
	*res = (char *)malloc(sizeof(char) * (count + 1));
	if (*res == 0)
		return (-1);
	index = 0;
	while (index < count)
	{
		(*res)[index] = str[*now + index];
		index++;
	}
	*now += count;
	(*res)[index] = 0;
	return (1);
}

static void	free_all(char ***res, int size)
{
	int		index;

	index = 0;
	while (index < size)
	{
		free((*res)[index]);
		index++;
	}
	free(*res);
	*res = 0;
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**res;
	int		index;
	int		now;

	if (s == 0)
		exit(EXIT_FAILURE);
	now = 0;
	index = 0;
	size = word_count(s, c) + 1;
	res = (char **)malloc(sizeof(char *) * size);
	if (res == 0)
		exit(EXIT_FAILURE);
	res[size - 1] = 0;
	while (index < size - 1)
	{
		if (ft_make_word(&res[index], s, &now, c) == -1)
		{
			free_all(&res, index);
			break ;
		}
		index++;
	}
	return (res);
}
