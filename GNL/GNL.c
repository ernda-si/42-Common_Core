/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:27:16 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/22 14:15:22 by ernda-si         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return(NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
}

int	main(void)
{
	int	fd;
	// int	i;
	// i = 0;
	fd = open("test.txt", O_RDONLY);
	// while (i++ < 3)
	printf("GNL: %s\n", get_next_line(fd));
	close(fd);
}