/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:38:06 by ernda-si          #+#    #+#             */
/*   Updated: 2026/01/06 15:39:30 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_popen.h"

static size_t	ft_strlen(const char *str)
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

static char	*ft_strjoin(char *line, char *buff, size_t	line_len, size_t buff_len)
{
	size_t		i;
	size_t		j;
	char		*result;

	i = 0;
	j = 0;
	result = malloc(line_len + buff_len + 1);
	if (!result)
		return (free(line), NULL);
	while (i < line_len)
	{
		result[i] = line[i];
		i++;
	}
	while (j < buff_len)
		result[i++] = buff[j++];
	result[i] = '\0';
	return (free(line), result);
}

static int	cut_buff(char *buffer)
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
	static char	buffer[1 + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || fd > 1024 || 1 <= 0)
		return (NULL);
	while (bytes_read)
	{
		if (buffer[0] == 0)
			bytes_read = read(fd, buffer, 1);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
		if (cut_buff(buffer))
			break ;
	}
	return (line);
}