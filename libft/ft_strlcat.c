/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:14:47 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/31 09:17:40 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	c = 0;
	if (a > dstsize)
		a = dstsize;
	d = a;
	if (a < dstsize)
	{
		while (d < dstsize && c < b)
		{
			dst[d] = src[c];
			c++;
			d++;
		}
		if (d < dstsize)
			dst[d] = '\0';
		else
			dst[dstsize - 1] = '\0';
	}
	return (a + b);
}
