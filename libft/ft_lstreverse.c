/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:16:12 by erli              #+#    #+#             */
/*   Updated: 2018/11/09 11:07:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_swap_data_rev(t_list *list1, t_list *list2)
{
	void	*tmp;
	size_t	tmpsize;

	tmp = list1->content;
	tmpsize = list1->content_size;
	list1->content = list2->content;
	list1->content_size = list2->content_size;
	list2->content = tmp;
	list2->content_size = tmpsize;
}

void			ft_lstreverse(t_list *list)
{
	t_list *tmp_tail;
	t_list *tmp_head;

	if (list == NULL)
		return ;
	tmp_tail = list;
	while (tmp_tail->next != NULL)
		tmp_tail = tmp_tail->next;
	while (tmp_tail != list && tmp_tail->next != list)
	{
		tmp_head = list;
		ft_swap_data_rev(tmp_head, tmp_tail);
		while (tmp_head->next != tmp_tail)
			tmp_head = tmp_head->next;
		tmp_tail = tmp_head;
		list = list->next;
	}
}
