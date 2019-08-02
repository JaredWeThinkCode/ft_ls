/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:48:42 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/02 11:47:24 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cal_block(char **array, char *location, t_options flag_on)
{
	int				a;
	int				b;
	struct stat		filestat;

	a = 0;
	b = 0;
	location = ft_strjoin(location, "/");
	while (array[a] != NULL)
	{
		if (flag_on.flag_a != 1 && array[a][0] == '.')
			a++;
		else
		{
			lstat(ft_strjoin(location, array[a]), &filestat);
			b += filestat.st_blocks;
			a++;
		}
	}
	return (b);
}

void	ft_print_modes(struct stat filestat)
{
	if (S_ISLNK(filestat.st_mode))
		ft_printf("l");
	else if (S_ISDIR(filestat.st_mode))
		ft_printf("d");
	else
		ft_printf("-");
	ft_printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
}

void	ft_flag_l_pm(char *string)
{
	struct stat		filestat;
	struct passwd	*pw;
	struct group	*gp;
	char			*time;

	lstat(string, &filestat);
	pw = getpwuid(filestat.st_uid);
	gp = getgrgid(filestat.st_gid);
	time = ctime(&filestat.st_mtime);
	time = ft_strsub(time, 4, 12);
	ft_print_modes(filestat);
	if (pw != 0)
	{
		ft_printf("  %3i ", (int)filestat.st_nlink);
		ft_printf("%-8s  ", pw->pw_name);
		ft_printf("%-7s", gp->gr_name);
		ft_printf("%7i %s ", (int)filestat.st_size, time);
	}
	else
	{
		ft_printf("  %3i ", (int)filestat.st_nlink);
		ft_printf("%-8i  ", filestat.st_uid);
		ft_printf("%-7i", filestat.st_gid);
		ft_printf("%7i %s ", (int)filestat.st_size, time);
	}
}

void	ft_print_stats(char *array, char *location)
{
	char			*string;
	char			*path;
	struct stat		filestat;

	string = malloc(sizeof(char *) * 1024);
	path = ft_strnew(1);
	location = ft_strjoin(location, "/");
	string = ft_strdup(array);
	string = ft_strjoin(location, string);
	ft_flag_l_pm(string);
	lstat(string, &filestat);
	if (S_ISLNK(filestat.st_mode))
	{
		readlink(string, path, 32);
		ft_printf("%s -> %s\n", array, path);
	}
	else
		ft_printf("%s\n", array);
}

void	ft_print_l(char **array, char *location, t_options flag_on)
{
	int		a;

	a = ft_count_array(array) - 1;
	while (a >= 0)
	{
		if (flag_on.flag_a != 1 && flag_on.flag_t != 1)
			if (array[a][0] == '.')
				break ;
		if ((flag_on.flag_a != 1 && flag_on.flag_t == 1) && (array[a][0] == '.'))
			a--;
		else
		{
			ft_print_stats(array[a], location);
			a--;
		}
	}
}

void	ft_flag_l(char **array, char **location, t_options flag_on)
{
	int			a;
	static int	b;
	int			c;
	int			d;

	if (array[2] == NULL && flag_on.flag_a != 1)
	{
		b++;
		return ;
	}
	a = 0;
	c = ft_count_array(array) - 1;
	d = ft_cal_block(array, location[b], flag_on);
	ft_printf("total %i\n", d);
	if (flag_on.flag_lr != 1)
	{
		while (array[a] != NULL)
		{
			if (flag_on.flag_a != 1 && array[a][0] == '.')
				a++;
			else
			{
				ft_print_stats(array[a], location[b]);
				a++;
			}
		}
	}
	if (flag_on.flag_lr == 1)
		ft_print_l(array, location[b], flag_on);
	b++;
}
