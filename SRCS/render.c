§§§§§§§/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:41:45 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/11 16:03:58 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *map_data)
{
	m_data	*data;

	data = (m_data*)malloc(sizeof(m_data));

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");

	//draw_fc(data, map_data);

    int		a, b, c, d, e;
    void	*image = mlx_xpm_file_to_image(data->mlx, "textures/colour_bars_srgb.xpm", &a, &b);

    char *test;
	if (image == NULL)
		exit(31);
	

  	test = mlx_get_data_addr(image, &c, &d, &e);
    mlx_put_image_to_window(data->mlx, data->win, image, 0, 0);

	mlx_loop(data->mlx);
}
 