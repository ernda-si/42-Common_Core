/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:03:31 by kali              #+#    #+#             */
/*   Updated: 2025/02/07 16:42:32 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <sys/types.h>

int	close_win(int keycode, t_map *vars)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

void	generate_map(t_imgs *image, t_map *vars)
{
	// map_checker();
	char	*line;
	int		i = 0;
	int		x = 0;
	int		y = 0;
	int		fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line: %s", line);
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, image->floor, x, y);
				x += 50;
			}
			else if (line[i] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, image->wall, x, y);
				x += 50;
			}
			else if (line[i] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, image->coin, x, y);
				x += 50;
			}
			else if (line[i] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, image->exit, x, y);
				x += 50;
			}
			if (line[i] == 'P')
			{
				vars->player.posX = x;
				vars->player.posY = y;
				printf("player X: %d Y: %d\n", vars->player.posX, vars->player.posY);
				mlx_put_image_to_window(vars->mlx, vars->win, image->player, x, y);
				x += 50;
			}
			i++;
		}
		y += 50;
		x = 0;
		i = 0;
		line = get_next_line(fd);
	}
	close (fd);
}

int		movement(int keycode, t_map *vars)
{
	if (keycode == 119) // 'W' key
	{
		vars->player.posY += 50;
		return(printf("W key pressed | new Y: %d\n", vars->player.posY));
	}
	else if (keycode == 97) // 'A' key
	return(printf("A key pressed\n"));
	else if (keycode == 115) // 'S' key
	return(printf("S key pressed\n"));
	else if (keycode == 100) // 'D' key
	return(printf("D key pressed\n"));
	return (0);
}

int	key_handler(int key, t_map *vars)
{
	if (key == 65307)
		return (close_win(key, vars));
	else if (key == 97 || key == 119 || key == 115 || key == 100)
		return (movement(key,vars));
	printf("keycode: %d\n", key);
	return (0);
}

void	xpm_to_image(t_map map, t_imgs img)
{
	int		p;

	p = IMG_SIZE;
	img.floor = mlx_xpm_file_to_image(map.mlx, "assets/floor.xpm", &p, &p); // 0 for an empty space,
	img.wall = mlx_xpm_file_to_image(map.mlx, "assets/wall.xpm", &p, &p); // 1 for a wall
	img.coin = mlx_xpm_file_to_image(map.mlx, "assets/coin.xpm", &p, &p); // C for a collectible
	img.exit = mlx_xpm_file_to_image(map.mlx, "assets/exit.xpm", &p, &p); // E for a map exit
	img.player = mlx_xpm_file_to_image(map.mlx, "assets/player.xpm", &p, &p); // P for the player’s starting position
	generate_map(&img, &map);
}

int	get_x()
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open("map.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		while (line[size] == '1')
		{
			size++;
			if (line[size] == '\n')
			{
				close(fd);
				return(size);
			}
		}
		line = NULL;
	}
}

int	get_y()
{
	int		fd;
	int		size;
	char	*line;

	size = 0;
	fd = open("map.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || (line[0] == '\n' && size))
		{
			close(fd);
			return(size);
		}
		if (line[0] == '1')
			size++;
	}
}

int	main(void)
{
	t_imgs	image;
	t_map	vars;

	vars.player.posX = 0;
	vars.player.posY = 0;
	printf("x: %d\n", get_x());
	printf("y: %d\n", get_y());
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, get_x() * 50, get_y() * 50, "So_long");
	xpm_to_image(vars, image);
	mlx_key_hook(vars.win, key_handler, &vars);
	mlx_loop(vars.mlx);
	return(0);
}
