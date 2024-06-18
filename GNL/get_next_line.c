/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:23:14 by ernda-si          #+#    #+#             */
/*   Updated: 2024/06/18 18:37:42 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	line_len(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n' && i < BUFFER_SIZE + 0)
		i++;
	return (i);
}

char	*cpy_strs(char *res, char *buf)
{
	int	i;
	int	buflen;
	// printf("testcpy");
	buflen = line_len(buf);
	i = 0;
	res = (char *)malloc (sizeof(char) * line_len(buf) + 1);
	if (!res)
		return (NULL);
	while (buf[i] && buf[i] != '\n' && i < buflen)
	{
		// printf("cpy_strs");
		res[i] = buf[i];
		i++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	// printf("test\n");
	i = 0;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE + 0) > 0)
	{
		printf("%s\n", buffer);
		result = cpy_strs(result, buffer);
		if (!result)
			return (NULL);
		// printf("%s\n", result);
		i = 0;
		while (result && result[i])
		{
			if (result[i] == '\n')
				return (result);
			i++;
		}
		// printf("%s\n", result);
	}
	return("end of function");
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i++ < 3)
		printf("%s\n", get_next_line(fd));
	close(fd);
}
