/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_lr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:36:18 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/16 09:37:05 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_rev_array(char **array)
{
	int		a;
	int		b;
	char	**temp;

	a = 0;
	b = ft_count_array(array) - 1;
	temp = malloc(sizeof(temp) * MALLOC_SIZE);
	while (b >= 0)
		temp[a++] = ft_strdup(array[b--]);
	temp[a] = NULL;
	a = 0;
	while (temp[a] != NULL)
	{
		free(array[a]);
		array[a] = ft_strdup(temp[a]);
		a++;
	}
	array[a] = NULL;
	ft_free_array(temp, -1);
	return (array);
}
