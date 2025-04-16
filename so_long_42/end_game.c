#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	exit_game(t_game *game)
{
	int	w;

	w = 0;
	free_matrix(game->map);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	w += write(1, "Game closed\n", 13);
	exit(0);
	return (0);
}

int	end_game(t_game *game)
{
	int	w;

	w = 0;
	free_matrix(game->map);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	w += write(1, "You won!\n", 10);
	exit(1);
	return (0);
}