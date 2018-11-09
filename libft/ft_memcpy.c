/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:38:49 by erli              #+#    #+#             */
/*   Updated: 2018/11/07 09:58:09 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*srcbyte;
	unsigned char	*dstbyte;

	i = 0;
	srcbyte = (unsigned char *)src;
	dstbyte = (unsigned char *)dst;
	while (i < n)
	{
		dstbyte[i] = srcbyte[i];
		i++;
	}
	return (dst);
}
