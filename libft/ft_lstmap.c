/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:11:40 by erli              #+#    #+#             */
/*   Updated: 2018/11/09 11:13:04 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *))
{
	t_list	*maplst;
	t_list	*new_elem;

	if (list == NULL)
		return (NULL);
	new_elem = f(list);
	maplst = ft_lstnew(new_elem->content, new_elem->content_size);
	list = list->next;
	while (list != NULL)
	{
		new_elem = f(list);
		ft_lstaddlast(&maplst, ft_lstnew(new_elem->content,
			new_elem->content_size));
		list = list->next;
	}
	return (maplst);
}
