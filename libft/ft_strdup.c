/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:03:02 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/30 14:37:29 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	int		b;
	char	*c;

	a = ft_strlen(s1);
	b = 0;
	c = (char *)malloc(a + 1);
	if (!c)
		return (NULL);
	while (a > 0)
	{
		c[b] = s1[b];
		b++;
		a--;
	}
	c[b] = '\0';
	return (c);
}
