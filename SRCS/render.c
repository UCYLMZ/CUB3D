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

void	render(t_data *map_data)
{
	m_data	*data;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");

	draw_fc(data, map_data);

	mlx_loop(data->mlx);
}
 