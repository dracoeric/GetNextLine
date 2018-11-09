/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:06:16 by erli              #+#    #+#             */
/*   Updated: 2018/11/09 11:11:27 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **alist, t_list *new)
{
	t_list *tail;

	if (new != NULL)
	{
		if (*alist == NULL)
			*alist = new;
		else
		{
			tail = *alist;
			while (tail->next != NULL)
				tail = tail->next;
			tail->next = new;
		}
	}
}
