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
		printf("player pos_X: %d | player pois_Y: %d\n", game->p_x, game->p_y);
		key_hooks(keycode, game);
		if (temp != game->move_counter)
			printf("steps: %d\n", game->move_counter);
	}
	return (0);
}

void	move_handler(t_game *game)
{
	mlx_hook(game->win, 9, 1L << 21, generate_map, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
}
