/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:04:04 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/23 13:32:40 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	a;
	char	*b;

	a = ft_strlen(s);
	b = (char *)s;
	if (c == 0)
	{
		return (b + a);
	}
	while (a > 0)
	{
		a--;
		if (b[a] == c)
			return (b + a);
	}
	return (NULL);
}
