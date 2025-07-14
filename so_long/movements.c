/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:45 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/17 14:02:10 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_hooks(int keycode, t_game *game)
{
	if (keycode == W || keycode == ARROW_UP)
	{
		game->p_y -= MOVE_UP;
		move_up(game);
	}
	else if (keycode == A || keycode == ARROW_LEFT)
	{
		game->p_x -= MOVE_LEFT;
		move_left(game);
	}
	else if (keycode == S || keycode == ARROW_DOWN)
	{
		game->p_y += MOVE_DOWN;
		move_down(game);
	}
	else if (keycode == D || keycode == ARROW_RIGHT)
	{
		game->p_x += MOVE_RIGHT;
		move_right(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	int	temp;

	temp = game->move_counter;
	if (keycode == ESC)
		exit_game(game);
	else if (game->gameover && game->has_player == 0 && game->has_coin == 0)
		end_game(game);
	else if (!game->gameover)
	{
		key_hooks(keycode, game);
		if (temp != game->move_counter)
			ft_printf("moves: %d\n", game->move_counter);
	}
	return (0);
}

void	move_handler(t_game *game)
{
	mlx_hook(game->win, 9, 1L << 21, generate_map, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
}
