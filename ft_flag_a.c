#include "ft_ls.h"

void    ft_flag_a(char **array, int a)
{
	if (a > 0)
    {
        while (array[a] != NULL)
        {
            ft_printf("%s\n", array[a]);
            a--;
        }
    }
    else
        while (array[a] != NULL)
            ft_printf("%s\n", array[a++]);
}
