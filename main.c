/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:46:15 by erli              #+#    #+#             */
/*   Updated: 2018/11/11 14:41:01 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	**line;
	int		*fd;
	int		i;

	line = (char **)malloc(sizeof(char *));
	i = 1;
	if (argc == 2)
	{
		puts("Yup");
		fd = (int *)malloc(sizeof(int) * (argc - 1));
		while (i < argc)
		{
			fd[i] = open(argv[i], O_RDONLY);
			i++;
		}
		puts("fd done");
		i = 0;
		while (i < argc)
		{
			get_next_line(fd[i], line);
			puts("line read");
			ft_putstr(*line);
			i++;
		}		
		i = 0;
		while (i < argc)
		{
			get_next_line(fd[i], line);
			ft_putstr(*line);
			i++;
		}		
		i = 0;
		while (i < argc)
		{
			get_next_line(fd[i], line);
			ft_putstr(*line);
			i++;
		}		
	}
	return (0);
}
