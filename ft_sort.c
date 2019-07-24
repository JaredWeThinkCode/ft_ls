#include "ft_ls.h"

int     ft_count_array(char **array)
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
