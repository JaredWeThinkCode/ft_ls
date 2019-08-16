/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:28:32 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/11 12:11:29 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize(char *s1)
{
	char	*a;
	int		c;

	a = ft_memalloc(ft_strlen(s1));
	c = 0;
	if (ft_isalpha(s1[0]) == 1)
	{
		s1[0] = ft_toupper(s1[0]);
		a[0] = s1[0];
		c++;
	}
	while (s1[c] != '\0')
	{
		if (ft_isalpha(s1[c]) == 1 && ft_isalpha(s1[c - 1]) == 0)
		{
			s1[c] = ft_toupper(s1[c]);
			a[c] = s1[c];
			c++;
		}
		a[c] = s1[c];
		c++;
	}
	a[c] = '\0';
	return (a);
}
