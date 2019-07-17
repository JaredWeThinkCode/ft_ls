/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:02:19 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/17 13:16:30 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_count_array(char **array)
{
	int		a;

	a = 0;
	while (array[a] != NULL)
		a++;
	return (a);
}

void	ft_sort(char **array, int size)
{
	char	*sort;
	int		a;
	int		b;

	a = 0;
	b = 0;
	sort = malloc(sizeof(char *) * 1024);
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if ((ft_strcmp(array[a], array[b])) > 0)
			{
				ft_strcpy(sort, array[b]);
				ft_strcpy(array[b], array[a]);
				ft_strcpy(array[a], sort);
			}
			b++;
		}
		a++;
	}
}

char	**ft_readdir(char **array, char	*location)
{
	struct	dirent	*file;
	DIR				*loc;
	int				a;

	a = 0;
	loc = opendir(location);
	if (loc == NULL)
	{
		printf("ft_ls: %s: No such file or directory\n", location);
		exit(3);
	}
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

void	ft_print_line(char	**array, t_options	flag_on, char	**location)
{
	int			a;
	int			b;
	static int	c;

	a = 0;
	b = 0;
	while (location[b] != NULL)
		b++;
	if (b > 0)
		printf("\n%s:\n", location[c++]);
	while (array[a] != NULL && flag_on.flag_ini == 0)
	{
		while (array[a][0] == '.')
			a++;
		printf("%s\n", array[a]);
		a++;
	}
	while (array[a] != NULL && flag_on.flag_ini == 1)
	{
		if (flag_on.flag_a != 1)
		{
			while (array[a][0] == '.')
				a++;
		}
		if (flag_on.flag_lr == 1)
		{
			a = ft_count_array(array) - 1;
			if (flag_on.flag_a == 1)
			{
				while (a >= 0)
				{
					printf("%s\n", array[a]);
					a--;
				}
			}
			else
			{
				while (a >= 0)
				{
					if (array[a][0] == '.')
						break ;
					printf("%s\n", array[a]);
					a--;
				}
			}
			break ;
		}
		printf("%s\n", array[a]);
		a++;
	}
}

void	ft_check_flags(char **array, char *flags, char **location, t_options flag_on)
{
	int		a;

	a = 0;
	if (flags[0] == '-')
	{
		if (ft_strchr(flags, 'a'))
			flag_on.flag_a = 1;
		if (ft_strchr(flags, 'r'))
			flag_on.flag_lr = 1;
		flag_on.flag_ini = 1;
	}
	while (location[a] != NULL)
	{
		array = ft_readdir(array, location[a]);
		ft_print_line(array, flag_on, location);
		a++;
	}
}

void	ft_init_flag(t_options	flag_on)
{
	flag_on.flag_a = 0;
	flag_on.flag_lr = 0;
}

char	**ft_find_dir(char	**av)
{
	char	**dir;
	int		a;
	int		b;

	a = 1;
	b = 0;
	dir = (char **)malloc(sizeof(char *) * 1024);
	dir[0] = ft_strdup(".");
	while (av[a] != NULL)
	{
		if (av[a][0] != '-')
		{
			dir[b] = ft_strdup(av[a]);
			b++;
		}
		a++;
	}
	if (b == 0)
		b++;
	dir[b] = NULL;
	return (dir);
}

char	*ft_cat_av(char **av)
{
	char	*cat;
	int		a;

	a = 1;
	cat = ft_strdup("");
	while (av[a] != NULL && av[a][0] == '-')
	{
		cat = ft_strjoin(cat, av[a]);
		a++;
	}
	return (cat);
}

int		main(int ac, char **av)
{
	char		**array;
	char		*flags;
	char		**location;
	int			a;
	t_options	flag_on;

	array = (char **)malloc(sizeof(char *) * 1024);
	flag_on.flag_ini = 0;
	ft_init_flag(flag_on);
	a = 0;
	if (ac == 1)
	{
		array = ft_readdir(array, ".");
		ft_print_line(array, flag_on, NULL);
	}
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
				array = ft_readdir(array, location[a]);
				ft_print_line(array, flag_on, location);
				a++;
			}
		}
	}
	return (0);
}
