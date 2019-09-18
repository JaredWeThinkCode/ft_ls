/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:05:45 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/09/18 07:25:20 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_errno(char **array, char *location, t_options *flags)
{
	if (errno == 20)
	{
		array[0] = ft_strdup(location);
		array[1] = NULL;
		if (flags->flag_l == '1')
			array = ft_flag_l(array, ".", flags);
	}
	else
	{
		ft_putstr("ft_ls: ");
		perror(location);
	}
}

void	ft_init(char **array, char **location, t_options *flags, int a)
{
	if (a == -1)
	{
		location[0] = ft_strdup(".");
		location[1] = NULL;
		a = 0;
	}
	array = ft_readdir(array, location[a], flags);
	array = ft_flags_init(array, location, flags, a);
	ft_print_data(array, location, flags);
	if (location[a + 1] != NULL && array[0] != NULL)
		ft_free_array(array, ft_count_array(array) - 1);
}

char	**ft_readdir(char **array, char *location, t_options *flags)
{
	struct dirent	*file;
	DIR				*loc;
	int				a;

	a = 0;
	loc = opendir(location);
	while (loc != NULL && (file = readdir(loc)) != NULL)
	{
		if (flags->flag_a == '1' || flags->flag_f == '1')
			array[a++] = ft_strdup(file->d_name);
		else
		{
			if (file->d_name[0] != '.')
				array[a++] = ft_strdup(file->d_name);
		}
	}
	if (loc)
		closedir(loc);
	array[a] = NULL;
	if (a != 0 && a != 1 && flags->flag_f == '0')
		ft_sort_lex(array, ft_count_array(array));
	return (array);
}

void	ft_print_data(char **array, char **location, t_options *flags)
{
	int			a;
	static int	b;
	DIR			*loc;

	a = 0;
	if (!(loc = opendir(location[b])))
		ft_check_errno(array, location[b++], flags);
	else
	{
		if (ft_count_array(location) > 1)
		{
			ft_putstr(location[b++]);
			ft_putendl(":");
		}
	}
	if (loc)
		closedir(loc);
	while (array[a] != NULL)
		ft_putendl(array[a++]);
	if (location[b] != NULL && location[1] != NULL)
		ft_putchar('\n');
}

int		main(int ac, char **av)
{
	char		**array;
	char		**loc;
	char		**flags_str;
	t_options	flags;
	int			a;

	flags = ft_flag();
	array = malloc(sizeof(array) * flags.malloc * 25);
	loc = malloc(sizeof(loc) * flags.malloc * 25);
	flags_str = malloc(sizeof(flags_str) * flags.malloc);
	a = 0;
	if (ac == 1)
		ft_init(array, loc, &flags, -1);
	if (ac > 1)
	{
		flags_str = ft_find_flags(flags_str, av);
		flags = *ft_check_flags(flags_str, &flags);
		loc = ft_find_dir(loc, av, &flags);
		while (loc[a] != NULL && a < flags.malloc * 25 && flags.flag_err == '0')
			ft_init(array, loc, &flags, a++);
	}
	ft_free_array(array, -1);
	ft_free_array(loc, -1);
	ft_free_array(flags_str, -1);
	return (0);
}
