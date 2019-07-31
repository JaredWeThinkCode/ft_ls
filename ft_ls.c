/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:02:19 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/31 11:37:33 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_errno(char *location)
{
    if (errno == 20)
	    ft_printf("%s\n", location);
	if (errno == 2)
		ft_printf("ft_ls: %s: No such file or directory\n", location);
	exit(3);
}

char	**ft_readdir(char **array, char *location)
{
	struct dirent	*file;
	DIR				*loc;
	int				a;

	a = 0;
	if (location == NULL)
		location = ft_strdup(".");
	location = ft_strjoin(location, "/");
	loc = opendir(location);
	if (loc == NULL)
		ft_check_errno(location);
	while ((file = readdir(loc)) != NULL)
	{
		array[a] = ft_strdup(file->d_name);
		a++;
	}
	closedir(loc);
	array[a] = NULL;
	ft_sort(array, ft_count_array(array));
	return (array);
}

t_options   ft_flag(t_options flag_on)
{
    flag_on.flag_a = 0;
    flag_on.flag_lr = 0;
    flag_on.flag_t = 0;
    flag_on.flag_l = 0;
    flag_on.flag_ur = 0;
    flag_on.flag_ini = 0;
    return (flag_on);
}

int		main(int ac, char **av)
{
	char		**array;
	char		**location;
	char		*flags;
	int			a;
	t_options	flag_on;

	array = (char **)malloc(sizeof(char *) * 1024);
	flag_on.flag_ini = 0;
	flag_on = ft_flag(flag_on);
	a = 0;
	if (ac == 1)
		ft_ini(array, NULL, flag_on, 0);
	if (ac > 1)
	{
		flags = ft_cat_av(av);
		location = ft_find_dir(av);
		if (flags[0] == '-')
			ft_check_flags(array, flags, location, flag_on);
		else
		{
			while (location[a] != NULL)
			{
				ft_ini(array, location, flag_on, a);
				a++;
			}
		}
	}
	return (0);
}
