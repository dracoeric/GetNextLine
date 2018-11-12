/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:46:15 by erli              #+#    #+#             */
/*   Updated: 2018/11/12 16:11:35 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		*fd;
	int		i;
	int		over;
	int		count;

	line = NULL;
	i = 1;
	count = 0;
	if (argc >= 2)
	{
		fd = (int *)malloc(sizeof(int) * (argc - 1));
		while (i < argc)
		{
			fd[i] = open(argv[i], O_RDONLY);
			i++;
		}
		over = 1;
		while (over != 0)
		{
			i = 1;
			while (i < argc)
			{
				over = get_next_line(fd[i], &line);
				if (over != 0)
				{	
					ft_putstr(line);
					free(line);
					ft_putchar('\n');
				}
				i++;
			}
		}
		i = 1;
		while (i < argc)
		{
			close(fd[i]);
			i++;
		}
	}
/*	while ((over = get_next_line(0, &line)))
	{
		printf("ret = %d\n", over);
		ft_putstr(line);
		free(line);
		ft_putchar('\n');
	}*/
	return (0);
}
