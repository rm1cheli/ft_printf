/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:08:55 by rmicheli          #+#    #+#             */
/*   Updated: 2021/10/18 18:09:47 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (s == NULL)
	{
		ft_putstr ("(null)");
		return (6);
	}
	while (s[c])
	{
		write(1, &s[c], 1);
		c++;
	}
	return (c);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *p)
{
	int	b;

	b = 0;
	while (p[b])
		b++;
	return (b);
}

int	revstr(char *str1)
{
	int	i;
	int	len;
	int	temp;
	int	g;

	len = ft_strlen(str1);
	i = 0;
	while (i < len / 2)
	{
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
		i++;
	}
	g = ft_strlen(str1);
	ft_putstr(str1);
	return (g);
}
