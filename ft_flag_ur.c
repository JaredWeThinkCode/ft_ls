/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_ur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:21:23 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/31 14:46:58 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_print_ini(char **array)
{
    int     a;

    a = 0;
    if (array[2] == NULL)
        return ;
    else
        while (array[a] != NULL)
            (array[a][0] != '.') ? ft_printf("%s\n", array[a++]) : a++;
}

char	**ft_arraydup(char **array)
{
	char	**temp;
	int		a;

	temp = (char **)malloc(sizeof(char *) * 1024);
	a = 0;
	while (array[a] != NULL)
	{
		temp[a] = ft_strdup(array[a]);
		a++;
	}
	temp[a] = NULL;
	return (temp);
}

char	**ft_rec_loc(char *string, char **location)
{
	int		b;

	b = ft_count_array(location);
	location[b] = ft_strdup(string);
	location[b + 1] = NULL;
	return (location);
}

void	ft_array_one(char **loc)
{
	int		a = 0;
	while (loc[a] != NULL)
	{
		ft_printf("%s\n", loc[a]);
		a++;
	}
}

char	**ft_flag_ur(char **array, char **location, t_options flag_on)
{
	struct stat filestat;
	char		*string;
	int			a;
	int			b;

	a = 0;
	while (location[a] != NULL && a < 2)
	{
		b = 0;
		array = ft_readdir(array, location[a]);
		while (array[b] != NULL)
		{
			if (array[2] == NULL)
				break ;
			if (flag_on.flag_a != 1)
				while (array[b][0] == '.')
					b++;
			string = ft_strdup(array[b]);
			if (!(ft_strcmp(string, ".") == 0 || ft_strcmp(string, "..") == 0))
			{
				string = ft_strjoin(ft_strjoin(location[a], "/"), string);
				lstat(string, &filestat);
				if (S_ISDIR(filestat.st_mode) || S_ISLNK(filestat.st_mode))
					location = ft_rec_loc(string, location);
			}
			b++;
		}
		a++;
	}
	ft_sort(location, ft_count_array(location));
	return (location);
}
