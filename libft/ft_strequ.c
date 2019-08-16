/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:52:12 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/31 13:06:15 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	a;

	if (s1 == NULL || s2 == NULL)
		return (0);
	a = ft_strcmp(s1, s2);
	if (a == 0)
	{
		return (1);
	}
	else
		return (0);
}
