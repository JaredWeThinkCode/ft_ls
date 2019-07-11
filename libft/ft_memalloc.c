/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 09:34:12 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/24 09:41:35 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	a;
	char	*b;

	a = 0;
	b = (char *)malloc(size);
	if (b == NULL)
	{
		return (NULL);
	}
	while (a < size)
	{
		b[a] = '\0';
		a++;
	}
	return (b);
}
