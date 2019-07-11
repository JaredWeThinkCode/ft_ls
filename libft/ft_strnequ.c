/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:15:42 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/31 13:06:49 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	a;

	if (s1 == NULL || s2 == NULL)
		return (0);
	a = ft_strncmp(s1, s2, n);
	if (a == 0)
		return (1);
	else
		return (0);
}
