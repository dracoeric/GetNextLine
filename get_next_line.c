/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:43:47 by erli              #+#    #+#             */
/*   Updated: 2018/11/10 19:26:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_bookmark	*new_bm(const int	fd)
{
	t_bookmark	*new;
	char		*line_buf;

	if (!(new = (t_bookmark *)malloc(sizeof(t_bookmark))))
		return (0);
	if (!(line_buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	ft_bzero(line_buf, (BUFF_SIZE + 1));
	new->file_descriptor = fd;
	new->line_buf = line_buf;
	new->next = 0;
	return (new);
}

char		*get_bm_line(t_bookmark **list, const int fd)
{
	t_bookmark	*head;
	t_bookmark	*new;

	if (list == 0)
	{
		if (!(list = (t_bookmark **)malloc(sizeof(t_bookmark *))))
			return (0);
		*list = new_bm(fd);
		return ((*list)->line_buf);
	}
	head = *list;
	while (*list != 0)
	{
		if ((*list)->file_descriptor == fd)
			return ((*list)->line_buf);	
		*list = (*list)->next;
	}
	new = new_bm(fd);
	new->next = head;
	*list = new;
	return (new->line_buf);
}

void		store_bm(t_bookmark *list, const int fd, char* line_buf)
{
	if (list == 0 && fd == 0 && line_buf == 0)
		ft_putchar('c');
}

int			get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE +1];
	char				*line_buf;
	int					ret;
	static	t_bookmark	*bmlist = 0;

	if (line == 0)
		return (-1);
	line_buf = get_bm_line(&bmlist, fd);
	
	
}
