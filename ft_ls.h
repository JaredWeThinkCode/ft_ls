/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 09:01:41 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/16 12:31:02 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H
# define __FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>

typedef struct		s_options
{
	int				flag_a;
	int				flag_t;
	int				flag_l;
	int				flag_lr;
	int				flag_ur;
}					t_options;

char	**ft_readdir(char **array);
void	ft_sort(char **array, int size);
int		ft_count_array(char **array);

#endif
