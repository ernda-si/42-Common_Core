#include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x = 1;
	int		y = 1;
	int		color = 16711680;
	t_data	image;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Test!");
	image.img = mlx_new_image(mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	while (x++ < 250 && y++ < 250)
	{
		my_mlx_pixel_put(&image, x, y, (int)color--);
		
		mlx_put_image_to_window(mlx, mlx_win, image.img, x, y);
	}
	x = 1;
	y = 1;
/* 	while (x++ < 250 && y++ < 250)
	{
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	} */
	mlx_loop(mlx);
}
