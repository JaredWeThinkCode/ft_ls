/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:46:35 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/31 11:46:44 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_flag_a(char **array, int a)
{
	if (a > 0)
        while (array[a] != NULL)
            ft_printf("%s\n", array[a--]);
    else
        while (array[a] != NULL)
            ft_printf("%s\n", array[a++]);
}
