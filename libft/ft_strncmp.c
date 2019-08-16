/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:20:17 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/28 13:17:36 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	a = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((s1[a] != '\0' && s2[a] != '\0') && s1[a] == s2[a] && a < (n - 1))
	{
		a++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
