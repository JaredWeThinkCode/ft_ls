/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:57:34 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/06 09:00:24 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*r;
	unsigned char	d;

	a = 0;
	r = (unsigned char *)s;
	d = (unsigned char)c;
	while (a < n)
	{
		if (*r == d)
		{
			return (r);
		}
		r++;
		a++;
	}
	return (NULL);
}
