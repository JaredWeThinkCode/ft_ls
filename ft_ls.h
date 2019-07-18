/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:01:41 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/18 09:04:43 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>

typedef struct		s_options
{
	int				flag_a;
	int				flag_t;
	int				flag_l;
	int				flag_lr;
	int				flag_ur;
	int				flag_ini;
}					t_options;

char	**ft_readdir(char **array, char	*location, t_options flag_on);
void	ft_sort(char **array, int size);
int		ft_count_array(char **array);
void	ft_print_line(char **array, t_options flag_on, char **location);

#endif
