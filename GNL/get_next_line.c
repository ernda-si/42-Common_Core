/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:37:18 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/14 15:50:29 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	nllen(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return(i);
}

char	*nlcpy(char *buffer, char *line, int position)
{
	int	nlen;
	int	i;

	i = 0;
	nlen = nllen(buffer);
	line = (char *) malloc(sizeof(char) * nllen(buffer));
	while (nlen--)
	{
		printf("nlen: %d\n", nlen);
		// printf("teste\n");
		line[position] = buffer[i];
		i++;
		position++;
		printf("line bc: %s\n", line);
		printf("buffer bc: %s\n", buffer);
	}
	return(line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			position;

	position = 0;
	line = NULL;
	while(read(fd, buffer, BUFFER_SIZE) && *buffer)
	{
		if (*buffer != '\n' && *buffer)
		{
			line = nlcpy(buffer, line, position);
			break;
		}
		// printf("checking\n");
		printf("line ac: %s\n", line);
		printf("buffer ac: %s\n", buffer);
	}
	// printf("line ac2: %s\n", line);
	// printf("buffer ac2: %s\n", buffer);
	return(line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i++ < 2)
		printf("GNL: %s\n", get_next_line(fd));
	close(fd);
}