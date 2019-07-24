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
	char	**temp;
	int		b;

	b = 0;
	temp = (char **)malloc(sizeof(char *) * 1024);
	while (location[b] != NULL)
	{
		temp[b] = ft_strdup(location[b]);
		b++;
	}
	temp[b] = ft_strdup(string);
	temp[b + 1] = NULL;
	return (temp);
}

char	**ft_flag_ur(char **array, char **location, t_options flag_on)
{
	struct stat filestat;
	char		*string;
	int			a;
	int			b;

	a = 0;
	while (location[a] != NULL)
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
				if (S_ISDIR(filestat.st_mode))
					location = ft_rec_loc(string, location);
			}
			b++;
		}
		a++;
	}
	ft_sort(location, ft_count_array(location));
	return (location);
}
