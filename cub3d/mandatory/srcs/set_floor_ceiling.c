/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyhan <sangyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:31:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/05/14 14:46:57 by sangyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_number(char *num)
{
	int		i;
	char	*temp;
	int		number;

	temp = ft_strtrim(num, " 	");
	i = 0;
	while (temp[i])
	{
		if (!(ft_isdigit(temp[i])))
			return (-1);
		i++;
	}
	number = ft_atoi(temp);
	free(temp);
	if (number < 0 || number > 255)
		return (-1);
	return (number);
}

static int	make_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	set_floor(char *trim, int *cnt, t_museum *mu)
{
	char	*temp;
	char	**temp_split;
	int		color[3];

	if (mu->texture.floor != -1)
		ft_error("Error\nInvalid Floor");
	temp = ft_substr(trim, 1, ft_strlen(trim) - 1);
	temp_split = ft_split(temp, ',');
	free(temp);
	if (ft_strslen(temp_split) != 3)
		ft_error("Error\nInvalid Floor");
	color[0] = check_number(temp_split[0]);
	color[1] = check_number(temp_split[1]);
	color[2] = check_number(temp_split[2]);
	if (color[0] == -1 || color[1] == -1 || color[2] == -1)
		ft_error("Error\nInvalid Floor");
	free_strs(temp_split);
	mu->texture.floor = make_color(color[0], color[1], color[2]);
	*cnt += 1;
}

void	set_ceiling(char *trim, int *cnt, t_museum *mu)
{
	char	*temp;
	char	**temp_split;
	int		color[3];

	if (mu->texture.ceiling != -1)
		ft_error("Error\nInvalid Ceiling");
	temp = ft_substr(trim, 1, ft_strlen(trim) - 1);
	temp_split = ft_split(temp, ',');
	free(temp);
	if (ft_strslen(temp_split) != 3)
		ft_error("Error\nInvalid Ceiling");
	color[0] = check_number(temp_split[0]);
	color[1] = check_number(temp_split[1]);
	color[2] = check_number(temp_split[2]);
	if (color[0] == -1 || color[1] == -1 || color[2] == -1)
		ft_error("Error\nInvalid Ceiling");
	free_strs(temp_split);
	mu->texture.ceiling = make_color(color[0], color[1], color[2]);
	*cnt += 1;
}
