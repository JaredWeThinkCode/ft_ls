/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:55:43 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/02 11:45:43 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char *a, int c, va_list va)
{
	char	*b;
	int		d;

	if (a[c] == 's')
	{
		b = va_arg(va, char *);
		ft_putstr(b);
	}
	if (a[c] == 'c')
	{
		d = va_arg(va, int);
		ft_putchar(d);
	}
	if (a[c] == 'd' || a[c] == 'i')
	{
		d = va_arg(va, int);
		ft_putnbr(d);
	}
}

void	ft_print_space(int num)
{
	int		a;

	a = 0;
	while (a < num)
	{
		ft_putchar(' ');
		a++;
	}
}

int		ft_align(char *str, int c, va_list va)
{
	int		a;
	int		b;
	int		d;
	int		e;
	char	*string;

	b = c;
	if (str[c] == '-')
		c++;
	a = c;
	while (str[c] >= '0' && str[c] <= '9')
		c++;
	string = ft_strsub(str, a, c - 1);
	a = ft_atoi(string);
	if (str[c] == 's')
	{
		string = va_arg(va, char *);
		d = ft_strlen(string);
		if (str[b] == '-')
		{
			ft_putstr(string);
			ft_print_space(a - d);
		}
		else
		{
			ft_print_space(a - d);
			ft_putstr(string);
		}
	}
	if (str[c] == 'i' || str[c] == 'd')
	{
		e = va_arg(va, int);
		d = ft_nbrlen(e);
		if (str[b] == '-')
		{
			ft_putnbr(e);
			ft_print_space(a - d);
		}
		else
		{
			ft_print_space(a - d);
			ft_putnbr(e);
		}
	}
	return (c);
}

int		ft_printline(const char *str, va_list va)
{
	char	*a;
	int		c;

	a = (char *)str;
	c = 0;
	while (a[c] != '\0')
	{
		if (a[c] == '%')
		{
			c++;
			if (a[c] == '%')
				ft_putchar('%');
			else if ((a[c] >= '1' && a[c] <= '9') || a[c] == '-')
				c = ft_align(a, c, va);
			else if (a[c] == 's' || a[c] == 'c' || a[c] == 'd' || a[c] == 'i')
				ft_format(a, c, va);
		}
		else
			ft_putchar(a[c]);
		c++;
	}
	return (1);
}

int		ft_printf(const char *str, ...)
{
	va_list		va;
	int			a;

	va_start(va, str);
	a = ft_printline(str, va);
	va_end(va);
	return (a);
}
