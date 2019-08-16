/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_ur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:41:39 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/16 13:50:10 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_location(char **location, char *str, int a)
{
	char	**temp;
	int		b;
	int		c;

	b = 0;
	c = a + 1;
	temp = malloc(sizeof(temp) * 256);
	while (location[c] != NULL)
	{
		temp[b] = ft_strdup(location[c]);
		free(location[c]);
		b++;
		c++;
	}
	temp[b] = NULL;
	ft_location_join(location, temp, str, a);
	ft_free_array(temp, -1);
	return (location);
}

void	ft_location_join(char **location, char **temp, char *str, int a)
{
	int		b;
	int		c;

	b = 0;
	c = a + 2;
	location[a + 1] = ft_strdup(str);
	while (temp[b] != NULL)
	{
		location[c] = ft_strdup(temp[b]);
		c++;
		b++;
	}
	location[c] = NULL;
}

void	ft_recursive(char **array, char **location, int a)
{
	struct stat	filestat;
	char		**temp;
	int			b;
	int			c;

	b = 0;
	c = a;
	temp = malloc(sizeof(temp) * MALLOC_SIZE);
	while (array[b] != NULL)
	{
		temp[0] = ft_strjoin(location[a], "/");
		temp[1] = ft_strjoin(temp[0], array[b]);
		lstat(temp[1], &filestat);
		if (!(S_ISLNK(filestat.st_mode)))
			if (S_ISDIR(filestat.st_mode) && (ft_strcmp(array[b], ".") != 0) && (ft_strcmp(array[b], "..") != 0))
				location = ft_location(location, temp[1], c++);
		ft_free_array(temp, 1);
		b++;
	}
	free(temp);
}
