/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:05:45 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/16 13:54:58 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_errno(char *location)
{
	ft_putstr("ft_ls: ");
	perror(location);
}

void	ft_init(char **array, char **location, t_options flags, int a)
{
	if (a == -1)
	{
		location[0] = ft_strdup(".");
		location[1] = NULL;
		a = 0;
	}
	array = ft_readdir(array, location[a], flags);
	array = ft_flags_init(array, location, flags, a);
	ft_print_data(array, location);
	if (location[a + 1] != NULL && array[0] != NULL)
		ft_free_array(array, (ft_count_array(array) - 1));
}

char	**ft_readdir(char **array, char *location, t_options flags)
{
	struct dirent	*file;
	DIR				*loc;
	int				a;

	a = 0;
	loc = opendir(location);
	while (loc != NULL && (file = readdir(loc)) != NULL)
	{
		if (flags.flag_a == '1')
			array[a++] = ft_strdup(file->d_name);
		else
		{
			if (file->d_name[0] != '.')
				array[a++] = ft_strdup(file->d_name);
		}
	}
	closedir(loc);
	array[a] = NULL;
	if (a != 0 && a != 1)
		ft_sort_lex(array, ft_count_array(array));
	return (array);
}

void	ft_print_data(char **array, char **location)
{
	int			a;
	static int	b;
	DIR			*loc;

	a = 0;
	if (!(loc = opendir(location[b])))
		ft_check_errno(location[b++]);
	else
	{
		if (ft_count_array(location) > 1)
		{
			ft_putstr(location[b++]);
			ft_putendl(":");
		}
	}
	closedir(loc);
	while (array[a] != NULL)
		ft_putendl(array[a++]);
	if (location[b] != NULL && location[1] != NULL)
		ft_putchar('\n');
}

int		main(int ac, char **av)
{
	char		**array;
	char		**location;
	char		**flags_str;
	t_options	flags;
	int			a;

	array = malloc(sizeof(array) * MALLOC_SIZE);
	location = malloc(sizeof(location) * MALLOC_SIZE);
	flags_str = malloc(sizeof(flags_str) * MALLOC_SIZE);
	flags = ft_flag();
	a = 0;
	if (ac == 1)
		ft_init(array, location, flags, -1);
	if (ac > 1)
	{
		flags_str = ft_find_flags(flags_str, av);
		flags = ft_check_flags(flags_str, flags);
		location = ft_find_dir(location, av, flags);
		while (location[a] != NULL)
			ft_init(array, location, flags, a++);
	}
	ft_free_array(array, -1);
	ft_free_array(location, -1);
	ft_free_array(flags_str, -1);
	return (0);
}
