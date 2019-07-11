/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:51:59 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/30 15:04:09 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			c;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	c = n;
	if (a == NULL && b == NULL)
	{
		return (NULL);
	}
	if (b < a)
	{
		while (c--)
		{
			a[c] = b[c];
		}
	}
	else
	{
		dst = ft_memcpy(a, b, n);
	}
	return (dst);
}
