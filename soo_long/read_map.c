/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:51 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/16 17:34:21 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static void	free_close(char *map, char *map_temp, int fd)
{
	free(map);
	free(map_temp);
	close(fd);
}

static void	is_empty(int fd, char *map)
{
	char	first[1];
	int		rd;

	rd = 0;
	first[0] = '\0';
	if (fd < 0)
	{
		free(map);
		pexit("File does not exist!\n", 1);
	}
	rd += read(fd, first, 1);
	if (!first[0])
	{
		free(map);
		close(fd);
		pexit("Empty file!\n", 1);
	}
	close(fd);
	return ;
}

static void	is_newlines(int fd, char *map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] == '\n')
			i++;
		if (line[i])
		{
			close(fd);
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	free(map);
	pexit("Map is empty!\n", 1);
}

static void	nl_check(int fd, char *map)
{
	char	*line;
	int		line_len;
	char	*next;

	line = get_next_line(fd);
	while (line)
	{
		line_len = ft_strlen(line);
		if (line_len == 1 && line[0] == '\n')
		{
			free(line);
			close(fd);
			free(map);
			pexit("Invalid blank line in map!\n", 1);
		}
		if (line[line_len - 1] != '\n')
		{
			next = get_next_line(fd);
			if (next != NULL)
			{
				free(next);
				free(line);
				close(fd);
				free(map);
				pexit("Map line missing newline before EOF!\n", 1);
			}
			free(next);
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

char	**file_reader(char *map)
{
	char	**matrix_map;
	char	*map_temp;
	char	*line;
	char	*temp;
	int		fd;

	map = ft_strjoin("maps/", map);
	is_empty(open(map, O_RDONLY), map);
	is_newlines(open(map, O_RDONLY), map);
	nl_check(open(map, O_RDONLY), map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = map_temp;
		map_temp = ft_strjoin(temp, line);
		free(line);
		free(temp);
	}
	matrix_map = ft_split(map_temp, '\n');
	return (free_close(map, map_temp, fd), matrix_map);
}
