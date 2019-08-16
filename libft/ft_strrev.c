/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:28:29 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/12 13:41:18 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*a;
	size_t	b;
	size_t	c;

	b = ft_strlen(s);
	if (!(a = ft_memalloc(b + 1)))
		return (NULL);
	c = 0;
	while (c < ft_strlen(s))
	{
		a[c] = s[b - 1];
		b--;
		c++;
	}
	a[c] = '\0';
	return (a);
}
