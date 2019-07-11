/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:38:58 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/31 09:15:11 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;
	unsigned char	x;

	a = (unsigned char *)d;
	b = (unsigned char *)s;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (b[i] == x)
			return (a + i + 1);
		i++;
	}
	return (NULL);
}
