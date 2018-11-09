/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:34:45 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 16:48:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *list)
{
	while (list != NULL)
	{
		ft_putmem(list->content, list->content_size);
		ft_putstr("\n->\n");
		list = list->next;
	}
	ft_putstr("(null)\n");
}
