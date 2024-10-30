/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:12:12 by jeonghaecha       #+#    #+#             */
/*   Updated: 2024/03/26 08:21:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 

# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(int n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t	len, size_t	size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putchar(char c, int fd);
int		ft_putstr(char *str, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
size_t	ft_strslen(char **strs);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strcat(char *dest, char *src);
int		ft_atoi(const char *str);
char	*ft_trim(const char *str);

#endif