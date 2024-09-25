/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:20:25 by ernda-si          #+#    #+#             */
/*   Updated: 2024/09/11 12:55:06 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;	
	bytes_read = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
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
		line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
		// printf("Buff[fd:%d]: %s\n", fd, buffer);
		if (cut_buff(buffer))
			break ;
	}
	// printf("Line[fd:%d]: %s\n", fd, line);
	return (line);
}

int	main(void)
{
	int	fd;
	int	fd2;
	int	i;
	char	*line;

	i = 1;
	fd = open("text1", O_RDONLY);
	fd2 = open("text2", O_RDONLY);

	printf("BUFFER_SIZE: %d\n\n", BUFFER_SIZE);
	while ((line = get_next_line(fd)))
	{
		printf("GNL[%d][fd%d]: %s", i++, fd, line);
		free(line);
	}
	i = 1;
	while ((line = get_next_line(fd2)))
	{
		printf("GNL[%d][fd%d]: %s", i++, fd2, line);
		free(line);
	}
	printf("\n");
	close(fd);
	close(fd2);
}