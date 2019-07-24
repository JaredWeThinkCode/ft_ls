/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:01:41 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/22 15:47:37 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <grp.h>

typedef struct		s_options
{
    int             flag_a;
	int				flag_t;
	int				flag_l;
	int				flag_lr;
	int				flag_ur;
	int				flag_ini;
}					t_options;

int     ft_printf(const char *str, ...);
int     ft_cal_block(char **array, char *location, t_options flag_on);
int     ft_count_array(char **array);

char	*ft_cat_av(char **av);
char	**ft_rev_array(char **array);
char	**ft_remove_num(char **array);
char	**ft_flag_t(char **array, char *location);
char	**ft_arraydup(char **array);
char	**ft_rec_loc(char *string, char **location);
char	**ft_flag_ur(char **array, char **location, t_options flag_on);
char	**ft_find_dir(char **av);
char	**ft_readdir(char **array, char *location);

void	ft_flag_a(char **array, int a);
void	ft_flag_print(char **array, char **location, t_options flag_on);
void	ft_print_line(char **array, t_options flag_on, char **location);
void	ft_ini(char **array, char **location, t_options flag_on, int a);
void	ft_check_flags(char **array, char *flags, char **location, t_options flag_on);
void	ft_print_modes(struct stat filestat);
void	ft_flag_l_pm(char *string);
void	ft_print_stats(char *array, char *location);
void	ft_print_l(char **array, char *location, t_options flag_on);
void	ft_flag_l(char **array, char **location, t_options flag_on);
void	ft_flag_t_print(char **array, t_options flag_on);
void	ft_flag_lr(char **array, t_options flag_on);
void	ft_print_ini(char **array);
void	ft_check_errno(char *location);
void	ft_sort(char **array, int size);

t_options   ft_flag_ini(t_options flag_on);

#endif
