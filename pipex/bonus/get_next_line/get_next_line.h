/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:34:35 by haejeong          #+#    #+#             */
/*   Updated: 2024/01/21 19:53:33 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

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
int		gnl_init(t_list **save, int fd);
void	*gnl_free(t_list **save);
t_list	*gnl_strjoin(t_list **save, char *buf, int read_size);
char	*get_next_line(int fd);

#endif