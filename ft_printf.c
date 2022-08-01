/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:20:23 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/21 18:29:36 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	format_def(char s, va_list format)
{
	int	len;

	len = 0;
	if (s == 'd')
		len = ft_putnbr(va_arg(format, int), 0);
	else if (s == 's')
		len = ft_putstr(va_arg(format, char *));
	else if (s == 'c')
		len = ft_putchar(va_arg(format, int));
	else if (s == 'i')
		len = ft_putnbr(va_arg(format, int), 0);
	else if (s == 'p')
		len = putpointer(va_arg(format, void *));
	else if (s == 'u')
		len = ft_putnbr_u(va_arg(format, unsigned int), 0);
	else if (s == 'x')
		len = ft_16putnbr_low(va_arg(format, unsigned int));
	else if (s == 'X')
		len = ft_16putnbr_up(va_arg(format, unsigned int));
	else if (s == '%')
	{
		write(1, "%%", 1);
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *string, ...)
{
	int		c;
	int		len;
	va_list	format;

	c = 0;
	len = 0;
	if (!string)
		return (0);
	va_start(format, string);
	while (string[c])
	{
		if (string[c] == '%')
			len += format_def(string[++c], format);
		else
		{
			write (1, &string[c], 1);
			len++;
		}
		c++;
	}
	va_end(format);
	return (len);
}
