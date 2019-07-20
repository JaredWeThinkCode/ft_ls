/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:26:30 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/20 14:23:46 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	size_t	c;
	char	*b;

	if (s == NULL)
		return (NULL);
	a = start;
	c = 0;
	if (!(b = ft_memalloc(len + 1)))
		return (NULL);
	if (a > ft_strlen(s) || a + len > ft_strlen(s))
	{
		return (NULL);
	}
	while (c < len)
	{
		b[c] = s[a];
		c++;
		a++;
	}
	b[c] = '\0';
	return (b);
}
