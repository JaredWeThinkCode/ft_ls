/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:08:20 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/13 08:27:45 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		a->content = NULL;
		a->content_size = 0;
	}
	else
	{
		if (!(a->content = ft_memalloc(content_size)))
			return (NULL);
		a->content_size = content_size;
		ft_memcpy(a->content, content, content_size);
	}
	a->next = NULL;
	return (a);
}
