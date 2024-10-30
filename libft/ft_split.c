/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:05:49 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/19 12:02:27 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (arr);
}

static int	ft_num_str(char const *str, char c)
{
	int	i;
	int	flag;
	int	cnt;

	flag = 0;
	cnt = 0;
	i = 0;
	while (str[i])
	{
		if ((flag == 0) && (!(str[i] == c)))
		{
			cnt++;
			flag = 1;
		}
		if (str[i] == c)
			flag = 0;
		i++;
	}
	return (cnt);
}

static void	ft_free(char **arr, int k)
{
	while (k >= 0)
	{
		free(arr[k]);
		k--;
	}
	free(arr);
}

static int	ft_word_len(char const *str, char c, int start)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[start + i])
	{
		if (str[start + i] != c)
			cnt++;
		else
			return (cnt);
		i++;
	}
	return (cnt);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		k;
	char	**arr;

	k = -1;
	i = -1;
	arr = (char **)malloc(sizeof(char *) * (ft_num_str(str, c) + 1));
	if (!(arr))
		return (0);
	arr[ft_num_str(str, c)] = 0;
	while (str[++i])
	{
		if (str[i] != c)
		{
			arr[++k] = ft_strndup(str, i, ft_word_len(str, c, i));
			if (!(arr[k]))
			{
				ft_free(arr, k);
				arr = NULL;
				return (0);
			}
			i += ft_word_len(str, c, i) - 1;
		}
	}
	return (arr);
}
