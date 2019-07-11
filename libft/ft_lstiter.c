/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:24:17 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/13 08:54:29 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list	*a;
	t_list	*b;

	a = lst;
	if (lst != NULL)
	{
		while (a->next != NULL)
		{
			b = a->next;
			f(a);
			a = b;
		}
		f(a);
	}
}
