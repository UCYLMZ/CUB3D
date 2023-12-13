#include "cub3d.h"

void	calc_texture_pixel_color(t_data *data)
{
	int	color;

	color = 0;
	if (data->y < data->draw_start)
		img_pix_put(&data->img, data->x, data->y, data->skyc);
	else if (data->y >= data->draw_start && data->y <= data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (64 - 1);
		data->tex_pos += data->step;
		if (data->side == 0 && data->raydir_x > 0)
			color = get_pixel_in_texture(data->west, data->tex_x, data->tex_y);
		else if (data->side == 0 && data->raydir_x < 0)
			color = get_pixel_in_texture(data->east, data->tex_x, data->tex_y);
		else if (data->side == 1 && data->raydir_y > 0)
			color = get_pixel_in_texture(data->north, data->tex_x, data->tex_y);
		else if (data->side == 1 && data->raydir_y < 0)
			color = get_pixel_in_texture(data->south, data->tex_x, data->tex_y);
		img_pix_put(&data->img, data->x, data->y, color);
	}
	else
		img_pix_put(&data->img, data->x, data->y, data->floorc);
}