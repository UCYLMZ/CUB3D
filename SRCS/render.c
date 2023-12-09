/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:41:45 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/04 16:02:34 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define WIDTH 1200
#define HEIGHT 900

int create_rgb_color(int red, int green, int blue)
{
    return (red << 16 | green << 8 | blue);
}

void draw_fc(m_data *data, t_data *map_data)
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

void	render(t_data *map_data)
{
	m_data	*data;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");

	draw_fc(data, map_data);

	mlx_loop(data->mlx);
}
 