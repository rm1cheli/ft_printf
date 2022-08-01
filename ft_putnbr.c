/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:20:54 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/18 19:21:14 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int f)
{
	char	c;

	if (n == 2147483647)
		return (ft_putstr("2147483647"));
	else if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		write(1, "-", 1);
		f = ft_putnbr(-n, f++);
	}
	else if (n >= 10)
	{
		f = ft_putnbr(n / 10, f++);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = (n % 10) + '0';
		ft_putchar(c);
	}
	return (++f);
}

int	ft_putnbr_u(unsigned int n, int f)
{
	char	c;

	if (n == 2147483647)
		return (ft_putstr("2147483647"));
	else if (n < 0)
	{
		write(1, "-", 1);
		f = ft_putnbr(-n, f++);
	}
	else if (n >= 10)
	{
		f = ft_putnbr(n / 10, f++);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = (n % 10) + '0';
		ft_putchar(c);
	}
	return (++f);
}
