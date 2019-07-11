/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 07:56:02 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/31 12:36:30 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char	const *s, char (*f)(char))
{
	char	*a;
	size_t	b;
	size_t	c;

	if (s == NULL)
		return (NULL);
	b = ft_strlen(s);
	if (!(a = ft_memalloc(b + 1)))
		return (NULL);
	c = 0;
	while (c < b)
	{
		a[c] = f(s[c]);
		c++;
	}
	return (a);
}
