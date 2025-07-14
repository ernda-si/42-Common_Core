/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:49 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/16 19:54:22 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * IMG_SIZE, y * IMG_SIZE);
}

static void	put_player(t_game *game, void *image, int x, int y)
{
	game->p_x = x;
	game->p_y = y;
	put_image(game, image, x, y);
}

void	put_exit(t_game *game, int x, int y)
{
	if (game->has_coin == 0)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = mlx_xpm_file_to_image
			(game->mlx, "assets/exit.xpm", &game->row, &game->collum);
	}
	put_image(game, game->exit, x, y);
}

static void	choose_image(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		put_image(game, game->wall, x, y);
	else if (game->map[y][x] == 'P')
		put_player(game, game->player, x, y);
	else if (game->map[y][x] == 'C')
		put_image(game, game->coin, x, y);
	else if (game->map[y][x] == '0')
		put_image(game, game->floor, x, y);
	else if (game->map[y][x] == 'E' && game->has_coin == 0)
		put_exit(game, x, y);
	else if (game->map[y][x] == 'E')
	{
		game->exit_y = y;
		game->exit_x = x;
		put_image(game, game->floor, x, y);
	}
}

int	generate_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			choose_image(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
