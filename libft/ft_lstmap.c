/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:34:51 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/13 08:26:07 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *a;
	t_list *b;

	if (lst == NULL || f == NULL)
		return (NULL);
	b = f(lst);
	a = b;
	while (lst->next != NULL)
	{
		b->next = f(lst->next);
		b = b->next;
		lst = lst->next;
	}
	return (a);
}
