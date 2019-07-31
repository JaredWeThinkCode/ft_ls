/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:54:29 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/31 12:21:14 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    **ft_rev_array(char **array)
{
	int		a;
	int		b;
	char	**temp;

	a = 0;
	b = ft_count_array(array) - 1;
	temp = (char **)malloc(sizeof(char *) * 1024);
	while (b >= 0)
		temp[a++] = ft_strdup(array[b--]);
	temp[a] = NULL;
	return (temp);
}

char    **ft_remove_num(char **array)
{
	int		a;
	int		b;
	char	**temp;

	a = 0;
	temp = (char **)malloc(sizeof(char *) * 1024);
	while (array[a] != NULL)
    {
		b = 0;
		while (array[a][b] >= '0' && array[a][b] <= '9')
			b++;
        temp[a] = ft_strdup(array[a] + b);
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
		location = ft_strjoin(location, "/");
		string = ft_strdup(array[a]);
		string = ft_strjoin(location, string);
		lstat(string, &filestat);
		b = filestat.st_mtime;
		temp[a] = ft_itoa(b);
		b = filestat.st_mtimespec.tv_nsec;
		temp[a] = ft_strjoin(temp[a], ft_itoa(b));
		temp[a] = ft_strjoin(temp[a], array[a]);
		a++;
	}
	ft_sort(temp, ft_count_array(temp));
	temp = ft_remove_num(temp);
	temp = ft_rev_array(temp);
	return (temp);
}

void	ft_flag_t_print(char **array, t_options flag_on)
{
	int		a;

	a = 0;
	if (flag_on.flag_lr == 1)
	{
		a = ft_count_array(array) - 1;
		if (flag_on.flag_a != 1)
			while (a >= 0)
				(array[a][0] != '.') ? ft_printf("%s\n", array[a--]) : a--;
		if (flag_on.flag_a == 1)
			ft_flag_lr(array, flag_on);
	}
	else if (flag_on.flag_a == 1)
		ft_flag_a(array, 0);
	else
		while (array[a] != NULL)
			(array[a][0] == '.') ? a++ : ft_printf("%s\n", array[a++]);
}
