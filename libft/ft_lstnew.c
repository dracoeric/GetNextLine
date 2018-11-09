/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:16:55 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 16:02:43 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;
	void	*cont;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(cont = malloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memcpy(cont, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
