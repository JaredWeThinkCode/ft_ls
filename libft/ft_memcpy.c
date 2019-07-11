/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:12:56 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/30 15:02:40 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;
	char	*b;
	char	*c;

	a = 0;
	b = (char *)dst;
	c = (char *)src;
	if (b == NULL && c == NULL)
		return (NULL);
	while (a < n)
	{
		b[a] = c[a];
		a++;
	}
	return (dst);
}
