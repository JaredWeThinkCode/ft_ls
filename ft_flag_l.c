/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:29:49 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/16 13:43:43 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_add_space(char *temp, int pos, int size)
{
	char	**array;
	char	*str;
	char	*new;
	int		a;

	a = 0;
	array = malloc(sizeof(array) * MALLOC_SIZE);
	str = malloc(MALLOC_SIZE);
	while (a < (size - ((int)ft_strlen(temp))))
		str[a++] = ' ';
	str[a] = '\0';
	array[0] = ft_strdup(str);
	array[1] = ft_strjoin(temp, " ");
	if (pos == 0)
		array[2] = ft_strjoin(array[0], array[1]);
	if (pos == 1)
		array[2] = ft_strjoin(array[1], array[0]);
	array[3] = NULL;
	free(str);
	new = ft_strdup(array[2]);
	ft_free_array(array, -1);
	return (new);
}

char	*ft_flagl_pm1(char *temp4, struct stat filestat)
{
	char	*temp;

	temp = malloc(MALLOC_SIZE);
	if (S_ISLNK(filestat.st_mode))
		temp[0] = 'l';
	else if (S_ISDIR(filestat.st_mode))
		temp[0] = 'd';
	else
		temp[0] = '-';
	temp[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
	temp[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
	temp[3] = (filestat.st_mode & S_IXUSR) ? 'x' : '-';
	temp[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
	temp[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
	temp[6] = (filestat.st_mode & S_IXGRP) ? 'x' : '-';
	temp[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
	temp[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
	temp[9] = (filestat.st_mode & S_IXOTH) ? 'x' : '-';
	temp[10] = '\0';
	temp4 = ft_strdup(temp);
	free(temp);
	return (temp4);
}

void	ft_flagl_pm2(char **temp, struct stat filestat)
{
	struct passwd	*pw;
	struct group	*gp;

	pw = getpwuid(filestat.st_uid);
	gp = getgrgid(filestat.st_gid);
	temp[3] = ft_strsub(ctime(&filestat.st_mtime), 4, 12);
	temp[4] = ft_flagl_pm1(temp[4], filestat);
	temp[5] = ft_itoa((int)filestat.st_nlink);
	temp[6] = ft_itoa((int)filestat.st_size);
	if (pw != 0)
	{
		temp[7] = ft_strdup(pw->pw_name);
		temp[8] = ft_strdup(gp->gr_name);
	}
	else
	{
		temp[7] = ft_itoa(filestat.st_uid);
		temp[8] = ft_itoa(filestat.st_gid);
	}
	temp[9] = ft_strdup(temp[0]);
}

char	*ft_temp_join(char **temp)
{
	char	**tab;
	char	*array;

	tab = malloc(sizeof(tab) * MALLOC_SIZE);
	tab[0] = ft_add_space(temp[5], 0, 4);
	tab[1] = ft_add_space(temp[7], 1, 6);
	tab[2] = ft_add_space(temp[8], 1, 6);
	tab[3] = ft_add_space(temp[6], 0, 6);
	tab[4] = ft_add_space(temp[3], 1, 12);
	tab[5] = ft_strjoin(temp[4], tab[0]);
	tab[6] = ft_strjoin(tab[1], tab[2]);
	tab[7] = ft_strjoin(tab[3], tab[4]);
	tab[8] = ft_strjoin(tab[5], tab[6]);
	tab[9] = ft_strjoin(tab[8], tab[7]);
	tab[10] = ft_strjoin(tab[9], temp[9]);
	tab[11] = NULL;
	array = ft_strdup(tab[10]);
	ft_free_array(tab, -1);
	return (array);
}

char	**ft_flag_l(char **array, char *location)
{
	struct stat	filestat;
	char		**temp;
	int			a;
	int			b;

	a = 0;
	b = 0;
	temp = malloc(sizeof(temp) * MALLOC_SIZE);
	while (array[a] != NULL)
	{
		temp[0] = ft_strdup(array[a]);
		temp[1] = ft_strjoin(location, "/");
		temp[2] = ft_strjoin(temp[1], temp[0]);
		lstat(temp[2], &filestat);
		b += filestat.st_blocks;
		ft_flagl_pm2(temp, filestat);
		free(array[a]);
		array[a++] = ft_temp_join(temp);
		ft_free_array(temp, 9);
	}
	free(temp);
	ft_cal_block(array, b);
	return (array);
}
