/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:24:47 by erli              #+#    #+#             */
/*   Updated: 2018/11/08 17:38:15 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lsttoupper(t_list *elem)
{
	void			*str;
	unsigned char	*strc;
	size_t			i;
	t_list			*new;

	i = 0;
	if (!(str = malloc(elem->content_size)))
		return (NULL);
	str = elem->content;
	strc = (unsigned char *)str;
	while (i < elem->content_size)
	{
		if (strc[i] >= 'a' && strc[i] <= 'z')
			strc[i] -= 32;
		i++;
	}
	new = ft_lstnew(str, elem->content_size);
	free(str);
	return (new);
}
