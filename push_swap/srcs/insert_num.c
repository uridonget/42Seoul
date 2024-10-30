/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:22:10 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/15 11:37:15 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_word_len(const char *str, int start)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[start + i])
	{
		if (!(ft_isspace(str[start + i])))
			cnt++;
		else
			return (cnt);
		i++;
	}
	return (cnt);
}

static int	is_num(const char *arr)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (arr[i] == '-')
	{
		flag = 1;
		i++;
	}
	while (arr[i])
	{
		if ((arr[i] < '0') || (arr[i] > '9'))
			return (0);
		i++;
	}
	if (i > 12)
		return (0);
	if ((i == 1) && (flag == 1))
		return (0);
	return (1);
}

static char	*ft_strndup(const char *src, int s, int n)
{
	int		i;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * (n + 1));
	if (!(arr))
		return (0);
	i = 0;
	while (i < n)
	{
		arr[i] = src[s + i];
		i++;
	}
	arr[i] = 0;
	if (!(is_num(arr)))
	{
		free(arr);
		print_err();
		return (0);
	}
	return (arr);
}

int	insert_num(char const *str, t_stack *stack)
{
	int		i;
	int		k;
	int		word_len;
	char	*arr;
	t_node	*new;

	i = -1;
	k = -1;
	while (str[++i])
	{
		if (!(ft_isspace(str[i])))
		{
			word_len = ft_word_len(str, i);
			arr = ft_strndup(str, i, word_len);
			if (!(arr))
				return (0);
			new = ft_new_node(ft_atoi(arr));
			free(arr);
			if (!(new))
				return (0);
			ft_add_node_back(stack, new);
			i += word_len - 1;
		}
	}
	return (1);
}
