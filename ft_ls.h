/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:01:41 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/08/28 14:12:37 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <grp.h>

# define MALLOC_SIZE 256

typedef struct	s_options
{
	int			malloc;
	char		flag_a;
	char		flag_t;
	char		flag_l;
	char		flag_lr;
	char		flag_ur;
	char		flag_f;
	char		flag_n;
	char		flag_err;
}				t_options;

int				ft_count_array(char **array);

char			**ft_find_flags(char **flags_str, char **av);
char			**ft_find_dir(char **location, char **av, t_options *flags);
char			**ft_readdir(char **array, char *location, t_options *flags);
char			**ft_flags_init(char **arr, char **loc, t_options *f, int a);
char			**ft_rev_array(char **array);
char			**ft_flag_l(char **array, char *location, t_options *flags);
char			*ft_flagl_pm1(char *temp4, struct stat filestat);
char			*ft_temp_join(char **temp);
char			*ft_add_space(char *temp, int pos, int size);

void			ft_location_join(char **loc, char **temp, char *str, int a);
void			ft_recursive(char **array, char **location, int a);
void			ft_sort_time(char **array, char *location);
void			ft_time_1(char **sort, char **array, int a, int b);
void			ft_time_2(char **sort, char **array, int a, int b);
void			ft_time_3(char **sort, char **array, int a, int b);
void			ft_init(char **array, char **location, t_options *flags, int a);
void			ft_cal_block(char **array, int num);
void			ft_flagl_pm2(char **t, struct stat fil, char *l, t_options *f);
void			ft_free_array(char **array, int num);
void			ft_print_data(char **array, char **location, t_options *flags);
void			ft_sort_lex(char **array, int size);
void			ft_check_errno(char **array, char *location, t_options *flags);

t_options		ft_flag(void);
t_options		*ft_check_flags(char **flags_str, t_options *flags);

#endif
