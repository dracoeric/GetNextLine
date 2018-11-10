/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:42:05 by erli              #+#    #+#             */
/*   Updated: 2018/11/10 19:14:42 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# define	BUFF_SIZE 4096

typedef	struct	s_bookmark
{
	int					file_descriptor;
	char				*line_buf;
	struct s_bookmark	*next;
}				t_bookmark;

int		get_next_line(const int fd, char **line);

#endif
