/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:03:37 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/23 16:41:06 by ernda-si         ###   ########.fr       */
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
		return(i);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		printf("reached newline\n");
		return(i + 1);
	}
	return(i);
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

// void	cut_buff(char *buffer, int start)
// {
// 	int i;

// 	i = 0;
// 	while (buffer[start])
// 		buffer[i++] = buffer[start++];
// 	buffer[i] = '\0';
// }

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
	{
		printf("buffer: %s\n", buffer);
		line = ft_strjoin(line, buffer);
		if (!line)
			return(NULL);
		while (line && line[i] && hasnl(buffer))
		{
			if (line[i] == '\n')
				break;
			i++;
		}
		// if (hasnl(buffer))
		// {
		// 	cut_buff(buffer, hasnl(buffer));
		// 	break;
		// }
	}
	line[i] = '\0';
	printf("buffer af: %s\n", buffer);
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
	// printf("GNL: %s\n", get_next_line(fd));
	close(fd);
}