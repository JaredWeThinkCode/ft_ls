/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:37:15 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/28 12:47:46 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_lex(char **array, int size)
{
	char	*sort;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if ((ft_strcmp(array[a], array[b])) > 0)
			{
				sort = ft_strdup(array[a]);
				free(array[a]);
				array[a] = ft_strdup(array[b]);
				free(array[b]);
				array[b] = ft_strdup(sort);
				free(sort);
			}
			b++;
		}
		a++;
	}
}

void	ft_time_1(char **sort, char **array, int a, int b)
{
	struct stat	filestat1;
	struct stat	filestat2;

	sort[1] = ft_strjoin(sort[0], array[a]);
	sort[2] = ft_strjoin(sort[0], array[b]);
	stat(sort[1], &filestat1);
	stat(sort[2], &filestat2);
	sort[3] = ft_itoa(filestat1.st_mtimespec.tv_sec);
	sort[4] = ft_itoa(filestat2.st_mtimespec.tv_sec);
	sort[5] = ft_itoa(filestat1.st_mtimespec.tv_nsec);
	sort[6] = ft_itoa(filestat2.st_mtimespec.tv_nsec);
}

void	ft_time_2(char **sort, char **array, int a, int b)
{
	sort[7] = ft_strdup(array[a]);
	free(array[a]);
	array[a] = ft_strdup(array[b]);
	free(array[b]);
	array[b] = ft_strdup(sort[7]);
	free(sort[7]);
}

void	ft_time_3(char **sort, char **array, int a, int b)
{
	if ((ft_strcmp(sort[5], sort[6])) < 0)
		ft_time_2(sort, array, a, b);
	else
	{
		if ((ft_strcmp(array[a], array[b])) >= 0)
			ft_time_2(sort, array, a, b);
	}
}

void	ft_sort_time(char **array, char *location)
{
	int		a;
	int		b;
	char	**sort;

	a = 0;
	sort = malloc(sizeof(sort) * MALLOC_SIZE);
	while (array[a] != NULL)
	{
		b = a + 1;
		while (array[b] != NULL)
		{
			sort[0] = ft_strjoin(location, "/");
			ft_time_1(sort, array, a, b);
			if ((ft_strcmp(sort[3], sort[4])) < 0)
				ft_time_2(sort, array, a, b);
			if ((ft_strcmp(sort[3], sort[4])) == 0)
				ft_time_3(sort, array, a, b);
			ft_free_array(sort, 6);
			b++;
		}
		a++;
	}
	free(sort);
}
