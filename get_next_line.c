/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:43:47 by erli              #+#    #+#             */
/*   Updated: 2018/11/12 18:03:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void			add_to_line(char **line, char *str_add)
{
	char *old;

	old = *line;
	*line = ft_strjoin(*line, str_add);
	free(old);
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
	if (!(new = (t_bookmark *)malloc(sizeof(t_bookmark))))
		return (0);
	new->last_buf = ft_strnew(BUFF_SIZE + 1);
	new->file_descriptor = fd;
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
			ft_bzero(target->last_buf, BUFF_SIZE + 1);
			free(target->last_buf);
			free(target);
		}
	}
}

int				read_line(const int fd, char **line, t_bookmark *bm, char *buf)
{
	int		ret;
	char	str_add[BUFF_SIZE + 1];
	int		first_read;

	ret = BUFF_SIZE;
	first_read = 1;
	while (ft_strchr(buf, 10) == NULL && ret == BUFF_SIZE)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		ft_bzero(str_add, BUFF_SIZE + 1);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0 && first_read == 1 && bm->last_buf[0] == '\0')
			return (0);
		else if (first_read == 1)
			*line = ft_strdup(bm->last_buf);
		first_read = 0;
		ft_memccpy(str_add, buf, 10, BUFF_SIZE);
		add_to_line(line, str_add);
	}
	if (ft_strchr(buf, 10) != NULL)
		buf = ft_strncpy(buf, ft_strchr(buf, 10) + 1, BUFF_SIZE);
	else if (ft_strchr(buf, 0) != buf + BUFF_SIZE)
		ft_bzero(buf, BUFF_SIZE + 1);
	bm->last_buf = ft_strncpy(bm->last_buf, buf, BUFF_SIZE + 1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_bookmark			*bm;
	static	t_bookmark	*bmlist = 0;
	char				buf[BUFF_SIZE + 1];

	if (line == 0 || fd < 0 || read(fd, buf, 0) == -1)
		return (-1);
	bm = bm_get(&bmlist, fd);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (ft_memccpy(bm->last_buf, bm->last_buf, 10, BUFF_SIZE) != NULL)
	{
		ft_memccpy(buf, bm->last_buf, 10, BUFF_SIZE);
		bm->last_buf = ft_strncpy(bm->last_buf,
			ft_strchr(bm->last_buf, 10) + 1, BUFF_SIZE);
		*line = ft_strdup(buf);
	}
	else if (!(read_line(fd, line, bm, buf)))
	{
		bm_free(&bmlist, fd);
		return (0);
	}
	if (ft_strchr(*line, 10) != NULL)
		*ft_strchr(*line, 10) = '\0';
	return (1);
}
