/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:03:37 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/27 18:11:34 by ernda-si         ###   ########.fr       */
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
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	size_t		i;
	size_t		j;
	char		*result;

	i = 0;
	j = 0;
	result = malloc(ft_strlen(line) + ft_strlen(buff) + 1);
	if (!result)
		return (free(line), NULL);
	while (i < ft_strlen(line))
	{
		result[i] = line[i];
		i++;
	}
	while (j < ft_strlen(buff))
	{
		result[i++] = buff[j++];
	}
	result[i] = '\0';
	return (free(line), result);
}

int	cut_buff(char *buffer)
{
	long	i;
	long	j;

	j = -1;
	i = 0;
	while (buffer[i])
	{
		if (j != -1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n' && j == -1)
			j++;
		buffer[i++] = '\0';
	}
	return (j != -1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes_read)
	{
		if (buffer[0] == 0)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		line = ft_strjoin(line, buffer);
		if (cut_buff(buffer))
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char	*line;

// 	i = 1;
// 	fd = open("test.txt", O_RDONLY);

// 	printf("BUFFER_SIZE: %d\n\n", BUFFER_SIZE);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("GNL[%d]: %s", i++, line);
// 		free(line);
// 	}
// 	close(fd);
// }