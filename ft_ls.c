/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:02:19 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/19 17:34:45 by jnaidoo          ###   ########.fr       */
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
				sort = ft_strdup(array[a]);
				array[a] = ft_strdup(array[b]);
				array[b] = ft_strdup(sort);
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
	if (errno == 2)
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
		location = ft_strjoin(location, "/");
		string = ft_strdup(array[a]);
		string = ft_strjoin(location, string);
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

//Test Function
void	printarray(char **array)
{
	int		a;

	a = 0;
	while (array[a] != NULL)
	{
		printf("%s\n--", array[a]);
		a++;
	}
}

int		ft_cal_block(char **array, t_options flag_on)
{
	int				a;
	int				b;
	struct stat		filestat;

	a = 0;
	b = 0;
	if (flag_on.flag_a == 1)
	{
		while (array[a] != NULL)
		{
			stat(array[a], &filestat);
			b = b + (int)filestat.st_blocks;
			a++;
		}
	}
	else
	{
		while (array[a] != NULL)
		{
			while (array[a][0] == '.')
				a++;
			stat(array[a], &filestat);
			b = b + (int)filestat.st_blocks;
			a++;
		}
	}
	return (b);
}

void	ft_flag_l_pm(char *string)
{
	struct stat		filestat;
	struct passwd	*pw;
	struct group	*gp;
	char			*time;

	
	stat(string, &filestat);
	pw = getpwuid(filestat.st_uid);
	gp = getgrgid(filestat.st_gid);
	time = ctime(&filestat.st_mtime);
	time = ft_strsub(time, 4, 12);
	printf( (S_ISDIR(filestat.st_mode)) ? "d" : "-");
	printf( (filestat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (filestat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (filestat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (filestat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (filestat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (filestat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (filestat.st_mode & S_IROTH) ? "r" : "-");
	printf( (filestat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (filestat.st_mode & S_IXOTH) ? "x" : "-");
	printf("  %2i %s  %s%7i %s ", (int)filestat.st_nlink, pw->pw_name, gp->gr_name, (int)filestat.st_size, time);
}

void	ft_print_l(char **array, char *location, t_options flag_on)
{
	char	*string;
	int		a;
	int		b;

	a = ft_count_array(array) - 1;
	b = ft_cal_block(array, flag_on);
	printf("total %i\n", b);
	while (a >= 0)
	{
		if (flag_on.flag_a != 1)
			if (array[a][0] == '.')
				break ;
		location = ft_strjoin(location, "/");
		string = ft_strdup(array[a]);
		string = ft_strjoin(location, string);
		ft_flag_l_pm(string);
		printf("%s\n", array[a]);
		a--;
	}
}

void	ft_flag_l(char **array, char *location, t_options flag_on)
{
	char		*string;
	int			a;
	int			b;

	a = 0;
	string = malloc(sizeof(char *) * 1024);
	if (flag_on.flag_t == 3)
		array = ft_flag_t(array, location); 
	if (flag_on.flag_lr != 2)
	{
		b = ft_cal_block(array, flag_on);
		printf("total %i\n", b);
		while (array[a] != NULL)
		{
			if (flag_on.flag_a != 1)
				while (array[a][0] == '.')
					a++;
			location = ft_strjoin(location, "/");
			string = ft_strdup(array[a]);
			string = ft_strjoin(location, string);
			ft_flag_l_pm(string);
			printf("%s\n", array[a]);
			a++;
		}
	}
	if (flag_on.flag_lr == 2)
		ft_print_l(array, location, flag_on);
}

char	**ft_readdir(char **array, char *location, t_options flag_on)
{
	struct dirent	*file;
	DIR				*loc;
	int				a;

	a = 0;
	if (location == NULL)
		location = ft_strdup(".");
	location = ft_strjoin(location, "/");
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
	if (flag_on.flag_t == 3 && flag_on.flag_l != 4)
		array = ft_flag_t(array, location);
	if (flag_on.flag_l == 5)
		ft_flag_l(array, location, flag_on);
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

void	ft_flag_t_print(char **array, t_options flag_on)
{
	int		a;

	a = 0;
	if (flag_on.flag_lr == 2)
	{
		a = ft_count_array(array) - 1;
		if (flag_on.flag_a != 1)
			while (a >= 0)
				(array[a][0] != '.') ? printf("%s\n", array[a--]) : a--;
		if (flag_on.flag_a == 1)
			ft_flag_lr(array, flag_on);
	}
	else if (flag_on.flag_a == 1)
		ft_flag_a(array, 0);
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
	if (flag_on.flag_t != 3)
	{
		if (flag_on.flag_lr == 2 && flag_on.flag_l != 5)
			ft_flag_lr(array, flag_on);
		if (flag_on.flag_a == 1 && flag_on.flag_lr != 2 && flag_on.flag_l != 5)
			ft_flag_a(array, 0);
	}
	if (flag_on.flag_t == 3 && flag_on.flag_l != 5)
		ft_flag_t_print(array, flag_on);
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
			flag_on.flag_lr = 2;
		if (ft_strchr(flags, 't'))
			flag_on.flag_t = 3;
		if (ft_strchr(flags, 'l'))
			flag_on.flag_l = 5; 
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
	flag_on.flag_l = 0;
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
