/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlstone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:16:13 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 17:19:06 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlstone(t_list *elem)
{
	if (elem != NULL)
	{
		ft_putmem(elem->content, elem->content_size);
		ft_putstr(" -> ");
	}
	else
		ft_putstr("(null)\n");
}
