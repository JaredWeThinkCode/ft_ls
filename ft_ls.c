/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:02:19 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/18 12:24:20 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_count_array(char **array)
{
	int		a;

	if (array == NULL)
		return (0);
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

void	ft_check_errno(char *location)
{
	if (errno == 20)
		printf("%s\n", location);
	else
		printf("ft_ls: %s: No such file or directory\n", location);
	exit(3);
}

char	**ft_rev_array(char **array)
{
	int		a;
	int		b;
	char	**temp;

	a = 0;
	b = ft_count_array(array) - 1;
	temp = (char **)malloc(sizeof(char *) * 1024);
	while (b >= 0)
	{
		temp[a] = ft_strdup(array[b]);
		a++;
		b--;
	}
	temp[a] = NULL;
	return (temp);
}

char	**ft_remove_num(char **array)
{
	int		a;
	char	**temp;

	a = 0;
	temp = (char **)malloc(sizeof(char *) * 1024);
	while (array[a] != NULL)
	{
		temp[a] = ft_strdup(array[a] + 10);
		a++;
	}
	temp[a] = NULL;
	return (temp);
}

char	**ft_flag_t(char **array, char *location)
{
	struct stat filestat;
	int			a;
	int			b;
	char		**temp;
	char		*string;

	a = 0;
	b = 0;
	temp = (char **)malloc(sizeof(char *) * 1024);
	string = malloc(sizeof(char *) * 1024);
	while (array[a] != NULL)
	{
		ft_strjoin(location, "/");
		string = ft_strdup(array[a]);
		ft_strjoin(location, string);
		stat(string, &filestat);
		b = (int)filestat.st_mtime;
		temp[a] = ft_itoa(b);
		temp[a] = ft_strjoin(temp[a], array[a]);
		a++;
	}
	ft_sort(temp, ft_count_array(temp));
	temp = ft_remove_num(temp);
	temp = ft_rev_array(temp);
	return (temp);
}

char	**ft_readdir(char **array, char *location, t_options flag_on)
{
	struct dirent	*file;
	DIR				*loc;
	int				a;

	a = 0;
	if (location == NULL)
		location = ft_strdup(".");
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
	if (flag_on.flag_t == 2)
		array = ft_flag_t(array, location);
	return (array);
}

void	ft_flag_a(char **array, int a)
{
	if (a == 0)
	{
		while (array[a] != NULL)
		{
			printf("%s\n", array[a]);
			a++;
		}
	}
	if (a > 0)
	{
		while (array[a] != NULL)
		{
			printf("%s\n", array[a]);
			a--;
		}
	}
}

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
			printf("%s\n", array[a]);
			a--;
		}
	}
}

void	ft_flag_t_(char **array, t_options flag_on)
{
	int		a;

	a = 0;
	if (flag_on.flag_lr == 1)
		ft_flag_lr(array, flag_on);
	else
	{
		while (array[a] != NULL)
		{
			(array[a][0] == '.') ? a++ : printf("%s\n", array[a++]);
		}
	}
}

void	ft_flag_print(char **array, t_options flag_on)
{
	if (flag_on.flag_t != 2)
	{
		if (flag_on.flag_lr == 1)
			ft_flag_lr(array, flag_on);
		if (flag_on.flag_a == 1 && flag_on.flag_lr != 1)
			ft_flag_a(array, 0);
	}
	if (flag_on.flag_t == 2)
		ft_flag_t_(array, flag_on);
}

void	ft_print_line(char **array, t_options flag_on, char **location)
{
	int			a;
	int			b;
	static int	c;

	a = 0;
	b = ft_count_array(location);
	if (b > 1)
		printf("\n%s:\n", location[c++]);
	while (array[a] != NULL && flag_on.flag_ini == 0 && array[3] != NULL)
	{
		while (array[a][0] == '.')
			a++;
		printf("%s\n", array[a]);
		a++;
	}
	if (array[a] != NULL && flag_on.flag_ini == 1)
		ft_flag_print(array, flag_on);
}

void	ft_ini(char **array, char **location, t_options flag_on, int a)
{
	if (location == NULL)
	{
		array = ft_readdir(array, ".", flag_on);
		ft_print_line(array, flag_on, NULL);
	}
	else
	{
		array = ft_readdir(array, location[a], flag_on);
		ft_print_line(array, flag_on, location);
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
		if (ft_strchr(flags, 't'))
			flag_on.flag_t = 2;
		flag_on.flag_ini = 1;
	}
	while (location[a] != NULL)
	{
		ft_ini(array, location, flag_on, a);
		a++;
	}
	exit(3);
}

char	**ft_find_dir(char **av)
{
	char	**dir;
	int		a;
	int		b;

	a = 1;
	b = 0;
	dir = (char **)malloc(sizeof(char *) * 1024);
	dir[0] = ".";
	while (av[a] != NULL)
	{
		if (av[a][0] != '-')
		{
			dir[b] = ft_strdup(av[a]);
			b++;
		}
		a++;
	}
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

void	ft_flag_ini(t_options flag_on)
{
	flag_on.flag_a = 0;
	flag_on.flag_lr = 0;
	flag_on.flag_t = 0;
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
	ft_flag_ini(flag_on);
	a = 0;
	if (ac == 1)
		ft_ini(array, NULL, flag_on, 0);
	if (ac > 1)
	{
		flags = ft_cat_av(av);
		location = ft_find_dir(av);
		if (flags[0] == '-')
			ft_check_flags(array, flags, location, flag_on);
		while (location[a] != NULL)
		{
			ft_ini(array, location, flag_on, a);
			a++;
		}
	}
	return (0);
}
