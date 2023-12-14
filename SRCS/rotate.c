/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:01:59 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/14 16:26:45 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data-> plane_x;
	data->dir_x = data-> dir_x * cos(-1 * (data->rot_speed))
		- data->dir_y * sin(-1 * (data->rot_speed));
	data->dir_y = old_dir_x * sin(-1 * (data->rot_speed))
		+ data-> dir_y * cos(-1 * (data->rot_speed));
	data->plane_x = data->plane_x * cos(-1 * (data->rot_speed))
		- data -> plane_y * sin(-1 *(data->rot_speed));
	data->plane_y = old_plane_x * sin(-1 * (data->rot_speed))
		+ data-> plane_y * cos(-1 * (data->rot_speed));
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(data-> rot_speed) - data->dir_y
		* sin(data->rot_speed);
	data->dir_y = old_dir_x * sin(data->rot_speed) + data->dir_y
		* cos(data->rot_speed);
	data->plane_x = data->plane_x * cos(data->rot_speed) - data->plane_y
		* sin(data->rot_speed);
	data->plane_y = old_plane_x * sin(data->rot_speed) + data->plane_y
		* cos(data->rot_speed);
}

void	fill_player_dir(t_data *data, double x, double y)
{
	data->dir_x = x;
	data->dir_x = y;
	if (x < 0.0)
		data->plane_y = -0.66;
	else if (x > 0.0)
		data->plane_y = 0.66;
	else
		data->plane_y = 0;
	if (y < 0.0)
		data->plane_x = 0.66;
	else if (y > 0.0)
		data->plane_x = -0.66;
	else
		data->plane_x = 0;
}
