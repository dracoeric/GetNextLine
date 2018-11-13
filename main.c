/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:46:15 by erli              #+#    #+#             */
/*   Updated: 2018/11/13 11:28:30 by erli             ###   ########.fr       */
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

int		main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;
	int		read;

	line = 0;
	i = 0;
	read = 1;
	puts("\n---=== Test de GetNextLine sur stdin ===---");
	while (i < 4)
	{
		printf("Essaie %d: (entrer une ligne)\n", i);
		if (get_next_line(0, &line) == 1)
		{
			printf("GNL donne:\n%s\n",line);
			free(line);
		}
		i++;
	}
	
	puts("\n---=== Test de GetNextLine sur un fichier ===---");
	fd1 = open("./test1.txt", O_RDONLY);
	while (read > 0)
	{
		read = get_next_line(fd1, &line);
		if (read == 1)
		{
			printf("GNL donne:\n%s\n",line);
			free(line);
		}
	}

	close(fd1);

	puts("\n---=== Test de GetNextLine sur un fd invalide ===---");
	printf("GNL = %d\n", get_next_line(fd1, &line));

	puts("\n---=== Test de GetNextLine sur trois fichier ===---");
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (get_next_line(fd1, &line))
	{
		printf("GNL de fd1 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd1, &line))
	{
		printf("GNL de fd1 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd2, &line))
	{
		printf("GNL de fd2 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd1, &line))
	{
		printf("GNL de fd1 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd3, &line))
	{
		printf("GNL de fd3 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd3, &line))
	{
		printf("GNL de fd3 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd2, &line))
	{
		printf("GNL de fd2 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd2, &line))
	{
		printf("GNL de fd2 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd1, &line))
	{
		printf("GNL de fd1 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd3, &line))
	{
		printf("GNL de fd3 donne:\n%s\n", line);
		free(line);
	}
	if (get_next_line(fd1, &line))
	{
		printf("GNL de fd1 donne:\n%s\n", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	
	return (0);
}
