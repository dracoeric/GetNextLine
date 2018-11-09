/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:49:09 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 17:03:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	t_list	*bubble;

	if (alist != NULL && *alist != NULL)
	{
		bubble = *alist;
		while (bubble != NULL)
		{
			del(bubble->content, bubble->content_size);
			free(bubble);
			bubble = bubble->next;
		}
		*alist = NULL;
	}
}
