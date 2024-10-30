/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:40:00 by haejeong          #+#    #+#             */
/*   Updated: 2023/11/07 17:01:27 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_write_str(const char *str, va_list argptr);
char	ft_check(char c, va_list argptr, int *cnt);
int		ft_print_c(char c, int *cnt);
int		ft_print_s(char *str, int *cnt);
int		ft_print_d_i(int n, int *cnt);
int		ft_print_p(void *ptr, int *cnt);
int		ft_print_u(unsigned int n, int *cnt);
int		ft_print_lx(unsigned int n, int *cnt);
int		ft_print_ux(unsigned int n, int *cnt);
int		ft_print_per(int *cnt);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c, int *cnt);
int		ft_putstr(char *str, int *cnt);

#endif
