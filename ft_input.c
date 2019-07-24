#include "ft_ls.h"

char    **ft_find_dir(char **av)
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
            dir[b++] = ft_strdup(av[a]);
		a++;
	}
	return (dir);
}

char	*ft_cat_av(char **av)
{
	char	*cat;
	int		a;

	a = 1;
	cat = ft_strnew(1);
	while (av[a] != NULL && av[a][0] == '-')
	{
		cat = ft_strjoin(cat, av[a]);
		a++;
	}
	return (cat);
}
