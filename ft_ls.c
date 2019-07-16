/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:02:19 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/16 12:44:57 by jnaidoo          ###   ########.fr       */
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
	sort = malloc(sizeof(char *) * 256);
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
		printf("ft_ls: ' ': NO such file or directory");
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

void	ft_print_line(char	**array)
{
	int		a;

	a = 0;
	while (array[a] != NULL)
	{
		/*if -a is active
		while (array[a][0] == '.')
			a++;*/
		printf("%s\n", array[a]);
		a++;
	}
}

int		main(int ac, char **av)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * 256);
	if (ac == 2 && av[1] != NULL)
	{
		if (!(ft_strchr(av[1], '-')))
			array = ft_readdir(array, av[1]);
		else
	}
	if (ac == 1 && av[1] == NULL)
	{
		array = ft_readdir(array, ".");
		ft_print
	}
	return (0);
}
