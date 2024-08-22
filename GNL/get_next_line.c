/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:03:37 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/22 14:39:38 by ernda-si         ###   ########.fr       */
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
	if (str[i] == '\n' && str[i])
		i++;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j; 
	char	*s3;

	if (!s1)
		return ((char *)s2);
	i = -1;
	j = 0;
	s3 = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (++i < ft_strlen(s1))
	{
		// printf("s3 on s1: %s\n", s3);
		s3[i] = s1[i];
	}
	while (j < ft_strlen(s2))
	{
		// printf("s3 on s2: %s\n", s3);
		s3[i++] = s2[j++];
	}
	s3[i + 1] = '\0';
	return (s3);
}

/* char	*cut_buff(char *buffer)
{
	char	*storage;
	int		i;
	int		len;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (!buffer[i])
			break;
		i++;
	}
	len = ft_strlen(buffer + i);
	storage = (char *) malloc(sizeof(char) * len + 1);
	while (len-- && i++)
		storage[i] = buffer[i];
	storage[i] = '\0';
	return(buffer);
} */

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
	}
	// cut_buff(buffer);
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