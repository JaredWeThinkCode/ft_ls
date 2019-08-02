/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_lr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:54:22 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/02 11:49:22 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flag_lr(char **array, t_options flag_on)
{
	int		a;

	a = ft_count_array(array) - 1;
	if (flag_on.flag_a == 1)
		ft_flag_a(array, a);
	else
	{
		while (a >= 0)
		{
			if (array[a][0] == '.')
				break ;
			ft_printf("%s\n", array[a--]);
		}
	}
}
