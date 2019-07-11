/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:06:09 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/11 15:05:37 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(char const *s, char c)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (s[0] != c)
		b++;
	while (s[a] != '\0')
	{
		if (s[a] == c && s[a + 1] != c && s[a + 1] != '\0')
			b++;
		a++;
	}
	return (b);
}

static int	ft_cntwrdlen(char const *s, int start, char c)
{
	int		a;

	a = 0;
	if (!s)
		return (0);
	while (s[start] != c && s[start] != '\0')
	{
		a++;
		start++;
	}
	return (a);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		b;
	int		d;
	int		e;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (a = ft_memalloc(1));
	b = ft_cntwrd(s, c);
	if (!(a = (char **)ft_memalloc(sizeof(char *) * (b + 1))))
		return (NULL);
	d = 0;
	e = 0;
	while (d < b)
	{
		while (s[e] == c && s[e] != '\0')
			e++;
		a[d] = ft_strsub(s, e, ft_cntwrdlen(s, e, c));
		while (s[e] != c && s[e] != '\0')
			e++;
		d++;
	}
	a[d] = 0;
	return (a);
}
