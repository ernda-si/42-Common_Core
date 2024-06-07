/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:24:52 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/07 19:18:38 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buff;

	buff = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buff || fd < 0)
		return (NULL);
	read(fd, buff, BUFFER_SIZE + 1);
	return (buff);
}
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char *gnl;

	fd = open ("test.txt", O_RDONLY);
	gnl = get_next_line(fd);
	printf("%s\n\n", gnl);
	printf("fd: %d\n", fd);
	free(gnl);
	close(fd);
}