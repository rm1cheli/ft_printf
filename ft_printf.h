/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:21:33 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/18 19:21:34 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *p);
int		revstr(char *str1);
int		ft_16putnbr_low(unsigned int c);
int		ft_16putnbr_up(unsigned int c);
int		putpointer(void *h);
int		ft_putnbr_u(unsigned int n, int f);
int		ft_putnbr(int n, int f);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_printf(const char *string, ...);
int		format_def(char s, va_list format);
char	*mal(unsigned long long c);

#endif