/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:52:30 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/28 15:33:49 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *a;
	t_list *b;

	a = *alst;
	while (a->next != NULL)
	{
		b = a->next;
		del(a->content, a->content_size);
		a = b;
	}
	del(a->content, a->content_size);
	*alst = NULL;
}
