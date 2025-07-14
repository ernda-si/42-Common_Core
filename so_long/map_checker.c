/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:51 by kali              #+#    #+#             */
/*   Updated: 2025/02/07 15:09:01 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_walls(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return(1);
}

int map_checker(void)
{
	int		fd;
	char	*line;
	int		flag;

	flag = 0;
	fd = open("map.ber", O_RDWR);
	line = "\0";
	if (!line)
		return(0);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (flag == 0 && check_walls(line))
		{
			printf("wall check: %d\n", check_walls(line));
			flag++;
		}
		if (flag)
			flag++;
		if (!line)
			break;
	}
	printf("flag: %d\n", flag);
	close(fd);
	return (1);
}
