/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:46:59 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/02 13:31:04 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_flag_print(char **array, char **location, t_options flag_on)
{
	if (flag_on.flag_ur == 1 && flag_on.flag_a != 1 && flag_on.flag_lr != 1 && flag_on.flag_t != 1 && flag_on.flag_l != 1)
		ft_print_ini(array);
	if (flag_on.flag_l == 1)
		ft_flag_l(array, location, flag_on);
	if (flag_on.flag_lr == 1 && flag_on.flag_l != 1 && flag_on.flag_t != 1)
		ft_flag_lr(array, flag_on);
	if (flag_on.flag_a == 1 && flag_on.flag_lr != 1 && flag_on.flag_l != 1 && flag_on.flag_t != 1)
		ft_flag_a(array, 0);
	if (flag_on.flag_t == 1 && flag_on.flag_l != 1)
		ft_flag_t_print(array, flag_on);
}

void			ft_print_line(char **array, t_options flag_on, char **location)
{
	int			a;
	int			b;
	static int	c;

	a = 0;
	b = ft_count_array(location);
	if (b > 1)
		ft_printf("\n%s:\n", location[c++]);
	if (array[a] != NULL && flag_on.flag_ini == 0 && array[2] != NULL)
		ft_print_ini(array);
	if (array[a] != NULL && flag_on.flag_ini == 1)
		ft_flag_print(array, location, flag_on);
	if (array[a] == NULL)
		return ;
}

void			ft_ini(char **array, char **location, t_options flag_on, int a)
{
	if (location == NULL)
	{
		array = ft_readdir(array, ".");
		ft_print_line(array, flag_on, NULL);
	}
	else
	{
		array = ft_readdir(array, location[a]);
		if (flag_on.flag_t == 1)
			array = ft_flag_t(array, location[a]);
		ft_print_line(array, flag_on, location);
	}
}

t_options		ft_flag_ini(t_options flag_on, char *flags)
{
	if (ft_strchr(flags, 'a'))
		flag_on.flag_a = 1;
	if (ft_strchr(flags, 'r'))
		flag_on.flag_lr = 1;
	if (ft_strchr(flags, 't'))
		flag_on.flag_t = 1;
	if (ft_strchr(flags, 'l'))
		flag_on.flag_l = 1;
	if (ft_strchr(flags, 'R'))
		flag_on.flag_ur = 1;
	flag_on.flag_ini = 1;
	return (flag_on);
}

void			ft_check_flags(char **array, char *flags, char **location, t_options flag_on)
{
	int		a;

	a = 0;
	if (flags[0] == '-')
		flag_on = ft_flag_ini(flag_on, flags);
	if (flag_on.flag_ur == 1)
		location = ft_flag_ur(array, location, flag_on);
	while (location[a] != NULL)
		ft_ini(array, location, flag_on, a++);
}
