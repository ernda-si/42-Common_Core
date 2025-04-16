#include "so_long.h"

char	**file_reader(char *map)
{
	char	**matrix_map;
	char	*map_temp;
	char	*line;
	char	*temp;
	int		fd;

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
	free(map_temp);
	close(fd);
	return (matrix_map);
}
