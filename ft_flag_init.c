/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:27:51 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/27 15:31:41 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options	ft_flag(void)
{
	t_options	flags;

	flags.flag_a = '0';
	flags.flag_lr = '0';
	flags.flag_t = '0';
	flags.flag_l = '0';
	flags.flag_ur = '0';
	flags.flag_f = '0';
	flags.flag_err = '0';
	return (flags);
}

char		**ft_flags_init(char **array, char **loc, t_options flags, int a)
{
	if (flags.flag_ur == '1')
		ft_recursive(array, loc, a);
	if (flags.flag_t == '1')
		ft_sort_time(array, loc[a]);
	if (flags.flag_lr == '1')
		array = ft_rev_array(array);
	if (flags.flag_l == '1')
		array = ft_flag_l(array, loc[a]);
	return (array);
}

int			ft_options(char **flags_str)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	str = "bcdeghijkmnopqsuvwxyzABCDEFGHIJKLMNOPQSTUVWXYZ";
	while (flags_str[a] != NULL)
	{
		b = 0;
		while (str[b] != '\0')
		{
			if (ft_strchr(flags_str[a], str[b]))
			{
				ft_putstr("ft_ls : illegal option -- ");
				ft_putchar(str[b]);
				ft_putchar('\n');
				ft_putendl("usage: ft_ls [Ralrt] [file ...]");
				return (1);
			}
			b++;
		}
		a++;
	}
	return (0);
}

t_options	ft_check_flags(char **flags_str, t_options flags)
{
	int	a;

	a = 0;
	while (flags_str[a] != NULL)
	{
		if (ft_strchr(flags_str[a], 'a'))
			flags.flag_a = '1';
		if (ft_strchr(flags_str[a], 'r'))
			flags.flag_lr = '1';
		if (ft_strchr(flags_str[a], 't'))
			flags.flag_t = '1';
		if (ft_strchr(flags_str[a], 'l'))
			flags.flag_l = '1';
		if (ft_strchr(flags_str[a], 'R'))
			flags.flag_ur = '1';
		if (ft_strchr(flags_str[a], 'f'))
			flags.flag_f = '1';
		a++;
	}
	if ((ft_options(flags_str)) == 1)
		flags.flag_err = '1';
	return (flags);
}
