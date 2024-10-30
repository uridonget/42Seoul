/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:47:25 by sangyhan          #+#    #+#             */
/*   Updated: 2024/05/11 17:19:17 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);

#endif