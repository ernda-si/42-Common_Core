/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:13:43 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/20 18:55:07 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		i2;
	char	*s3;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	else if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	i2 = 0;
	s3 = (char *) malloc (sizeof(char) * (len1 + len2 + 1));
	if (s3 == 0)
		return (NULL);
	while (++i < len1)
		s3[i] = s1[i];
	while (i2 < len2)
		s3[i++] = s2[i2++];
	s3[i] = '\0';
	return (s3);
}

int check_new_line(char *buffer)
{
	int i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *build_line(char *new_line, char *buffer)
{
	char *str;

	str = ft_strjoin(new_line, buffer);
	free (buffer);
	return (str);
	//remember to free the old line after creating the new one
}

char *save_and_cut(gnl)
{
	
}

char *get_next_line(int fd)
{
	static char	*gnl;
	char		*line;
	char		*buffer;
	int			chars_read;

	//first, check if static variable has a new_line
	
	buffer = calloc(sizeof(BUFFER_SIZE + 1), 1);
	while (!check_new_line(buffer))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE + 0);
		{
			if (chars_read == 0)
				break;
			buffer = build_line(line, buffer);
		}
	}
	save_and_cut(); //check if there is anything after newline, if so, save on char *gnl
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test22.txt", O_RDONLY);
	while(i++ < 3)
		printf("%s\n", get_next_line(fd));
	close (fd);
}
