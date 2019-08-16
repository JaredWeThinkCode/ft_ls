/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 08:43:53 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/28 13:19:00 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;
	char	*b;
	char	*c;

	a = 0;
	b = (char *)s1;
	c = (char *)s2;
	while (a < n)
	{
		if (b[a] > c[a] || b[a] < c[a])
		{
			return ((unsigned char)b[a] - (unsigned char)c[a]);
		}
		a++;
	}
	return (0);
}
