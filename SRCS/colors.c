#include "cub3d.h"

int	create_rgb_color(int red, int green, int blue)
{
    return (red << 16 | green << 8 | blue);
}

void	draw_fc(m_data *data, t_data *map_data)
{
    int	color;
	int	x;
	int	y;

	y = 0;
	color = create_rgb_color(map_data->c_red, map_data->c_green, map_data->c_blue);
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
 			mlx_pixel_put(data->mlx, data->win, x, y, color);
			x++;
		}
		y++;
	}
	color = create_rgb_color(map_data->f_red, map_data->f_green, map_data->f_blue);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
 			mlx_pixel_put(data->mlx, data->win, x, y, color);
			x++;
		}
		y++;
	}
}
