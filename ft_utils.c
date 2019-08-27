/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:43:34 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/27 12:07:05 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_count_array(char **array)
{
	int		a;

	a = 0;
	while (array[a])
		a++;
	return (a);
}

void	ft_free_array(char **array, int num)
{
	int		a;

	a = 0;
	if (num != -1)
		while (array[a] != NULL && a <= num)
			ft_strdel(&array[a++]);
	if (num == -1)
	{
		while (array[a] != NULL)
			ft_strdel(&array[a++]);
		free(array);
	}
}

void	ft_cal_block(char **array, int num)
{
	char	**str;

	if (array[0] == NULL)
		array[0] = ft_strdup("");
	str = malloc(sizeof(str) * MALLOC_SIZE);
	str[0] = ft_itoa(num);
	str[1] = ft_strjoin("total ", str[0]);
	str[2] = ft_strjoin(str[1], "\n");
	str[3] = ft_strjoin(str[2], array[0]);
	str[4] = NULL;
	free(array[0]);
	array[0] = ft_strdup(str[3]);
	ft_free_array(str, -1);
}

char	**ft_find_flags(char **flags_str, char **av)
{
	int		a;
	int		b;

	a = 1;
	b = 0;
	while (av[a] != NULL && av[a][0] == '-')
		flags_str[b++] = ft_strdup(av[a++]);
	flags_str[b] = NULL;
	return (flags_str);
}

char	**ft_find_dir(char **location, char **av, t_options flags)
{
	int		a;
	int		b;

	a = 1;
	b = 0;
	while (av[a] != NULL)
	{
		if (av[a][0] != '-')
			location[b++] = ft_strdup(av[a]);
		a++;
	}
	if (b == 0)
		location[b++] = ft_strdup(".");
	location[b] = NULL;
	ft_sort_lex(location, ft_count_array(location));
	if (flags.flag_lr == '1' && flags.flag_ur == '0' && location[1] != NULL)
		location = ft_rev_array(location);
	return (location);
}
