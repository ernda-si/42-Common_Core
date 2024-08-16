/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:02:53 by ernda-si          #+#    #+#             */
/*   Updated: 2024/08/16 16:57:53 by ernda-si         ###   ########.fr       */
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
	while (buffer[i] != '\n')
	{
		i++;
		if (buffer[i] == '\n')
			return(i);
	}
	return(i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*s3;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	else if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	j = 0;
	s3 = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (s3 == 0)
		return (NULL);
	while (++i < len1)
		s3[i] = s1[i];
	while (j < len2)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	while (!buffer[0])
	{
		while (read(fd, buffer, BUFFER_SIZE))
		{
			line = ft_strjoin(line, buffer);
			while (line && line[i] != '\n')
			{
				printf("buffer: %s\n", buffer);
				printf("line: %s\n", line);
				i++;
				if (line[i] == '\n')
				{
					line[i + 1] = '\0';
					return(line);
				}
			}
		}
		break;
	}
	return(line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i++ < 3)
		printf("GNL: %s\n", get_next_line(fd));
	close(fd);
}