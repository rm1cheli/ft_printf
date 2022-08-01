/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:07:37 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/21 18:29:38 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	low(char *num, unsigned long long c)
{
	int	i;

	i = 0;
	while (c != 0)
	{
		if (c % 16 < 10)
			num[i] = (c % 16) + '0';
		else
			num[i] = ((c % 16) - 10) + 'a';
		c /= 16;
		i++;
	}
	return (i);
}

char	*mal(unsigned long long c)
{
	int		b;
	char	*size;

	b = 0;
	while (c != 0)
	{
		c /= 16;
		b++;
	}
	size = malloc(sizeof(char) * (b + 1));
	if (!size)
		return (0);
	return (size);
}

int	ft_16putnbr_low(unsigned int c)
{
	int		i;
	char	*num;

	if (!c)
	{
		ft_putchar ('0');
		return (1);
	}
	i = 0;
	num = mal(c);
	if (!num)
		return (0);
	while (c != 0)
	{
		if (c % 16 < 10)
			num[i] = (c % 16) + '0';
		else
			num[i] = ((c % 16) - 10) + 'a';
		c /= 16;
		i++;
	}
	num[i] = '\0';
	i = revstr(num);
	free (num);
	return (i);
}

int	ft_16putnbr_up(unsigned int c)
{
	int		i;
	char	*num;

	if (!c)
	{
		ft_putchar ('0');
		return (1);
	}
	i = 0;
	num = mal(c);
	if (!num)
		return (0);
	while (c != 0)
	{
		if (c % 16 < 10)
			num[i] = (c % 16) + '0';
		else
			num[i] = ((c % 16) - 10) + 'A';
		c /= 16;
		i++;
	}
	num[i] = '\0';
	i = revstr(num);
	free (num);
	return (i);
}

int	putpointer(void *h)
{
	int					i;
	char				*num;
	unsigned long long	c;

	if (!h)
	{
		ft_putstr("0x0");
		return (3);
	}
	c = (unsigned long long)h;
	i = 0;
	num = mal(c);
	if (!num)
		return (6);
	i = low(num, c);
	ft_putstr ("0x");
	num[i] = '\0';
	i = revstr(num);
	free (num);
	return (i + 2);
}
