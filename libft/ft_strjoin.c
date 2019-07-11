/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:13:02 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/03 16:32:28 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		c;
	int		d;

	if (!s1 || !s2)
		return (NULL);
	c = 0;
	d = 0;
	if (!(a = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[c] != '\0')
	{
		a[c] = s1[c];
		c++;
	}
	while (s2[d] != '\0')
	{
		a[c + d] = s2[d];
		d++;
	}
	a[c + d] = '\0';
	return (a);
}
