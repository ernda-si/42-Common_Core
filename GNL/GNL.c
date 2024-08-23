/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:27:16 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/23 15:22:11 by ernda-si         ###   ########.fr       */
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

int	hasnl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return(0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return(1);
	return(0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(const char *line, const char *buff)
{
	int		i;
	int		j;
	int		linelen;
	int		bufflen;
	char	*result;

	i = 0;
	j = 0;
	linelen = ft_strlen(line);
	bufflen = ft_strlen(buff);
	result = (char *) malloc(linelen + bufflen + 1);
	if (!result)
		return(NULL);
	while (i < linelen)
	{
		result[i] = line[i];
		i++;
	}
	while (j < bufflen)
	{
		result[i + j] = buff[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	// int		i;

	// i = 0;
	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return(NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (!line)
			line = ft_strjoin(line, buffer);
		while (!hasnl(buffer) && read(fd, buffer, BUFFER_SIZE) > 0)
			line = ft_strjoin(line, buffer);
		break;
	}
	return(line);
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