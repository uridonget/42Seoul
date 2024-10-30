/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:14:36 by haejeong          #+#    #+#             */
/*   Updated: 2023/11/03 19:35:18 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	char	*str;
	int		len;
	int		nl;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_find_nl(t_list *save);
int		ft_init(t_list **save, int fd);
void	*ft_free(t_list **save);
t_list	*ft_strjoin(t_list **save, char *buf, int read_size);
char	*get_next_line(int fd);

#endif
