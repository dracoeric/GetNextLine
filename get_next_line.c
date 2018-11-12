/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:43:47 by erli              #+#    #+#             */
/*   Updated: 2018/11/12 09:24:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_bookmark		*bm_new(const int fd)
{
	t_bookmark	*new;
	char		*last_buf;

	if (!(new = (t_bookmark *)malloc(sizeof(t_bookmark))))
		return (0);
	if (!(last_buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	ft_bzero(last_buf, (BUFF_SIZE + 1));
	new->file_descriptor = fd;
	new->last_buf = last_buf;
	new->next = 0;
	return (new);
}

t_bookmark		*bm_get(t_bookmark **list, const int fd)
{
	t_bookmark	*bubble;
	t_bookmark	*new;

	if (list == 0)
	{
		if (!(list = (t_bookmark **)malloc(sizeof(t_bookmark *))))
			return (0);
		*list = 0;
	}
	bubble = *list;
	while (bubble != 0)
	{
		if (bubble->file_descriptor == fd)
			return (bubble);
		bubble = bubble->next;
	}
	new = bm_new(fd);
	new->next = *list;
	*list = new;
	return (new);
}

void			bm_free(t_bookmark **list, const int fd)
{
	t_bookmark	*prev;
	t_bookmark	*target;

	if (list != NULL && *list != NULL)
	{
		prev = *list;
		target = prev->next;
		while (target != NULL && target->file_descriptor != fd)
		{
			prev = target;
			target = target->next;
		}
		if (target != NULL)
		{
			prev->next = target->next;
			free(target->last_buf);
			free(target);
		}
	}
}

int				read_line(const int fd, char **line, t_bookmark *bm)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	str_add[BUFF_SIZE + 1];
	void	*ptr;

	ret = BUFF_SIZE;
	ptr = NULL;
	*line = ft_strtrim(bm->last_buf);
	while (ptr == NULL && ret == BUFF_SIZE)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		ft_bzero(str_add, BUFF_SIZE + 1);
		ret = read(fd, buf, BUFF_SIZE);
		ptr = memccpy(str_add, buf, 10, BUFF_SIZE);
		free(*line);
		*line = ft_strjoin(*line, str_add);
	}
	if (ret < BUFF_SIZE)
		return (0);
	if (ptr != NULL)
		bm->last_buf = ft_strncpy(bm->last_buf, (char *)ptr, BUFF_SIZE + 1);
	if (bm->last_buf[0] == '\0')
		return (read(fd, bm->last_buf, 1));
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_bookmark			*bm;
	static	t_bookmark	*bmlist = 0;
	int					read_out;

	if (line == 0)
		return (-1);
	*line = 0;
	bm = bm_get(&bmlist, fd);
	if (fd < 0)
		return (-1);
	if (fd <= 1)
		ft_bzero(bm->last_buf, BUFF_SIZE + 1);
	read_out = read_line(fd, line, bm);
	if (read_out == 0)
		bm_free(&bmlist, fd);
	return (read_out);
}
