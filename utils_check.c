#include "cub3d.h"

void	check_rgb(t_data *map_data)
{
	if (map_data->c_red < 0 || map_data->c_red > 255
		|| map_data->c_green < 0 || map_data->c_green > 255
		|| map_data->c_blue < 0 || map_data->c_blue > 255
		|| map_data->f_red < 0 || map_data->f_red > 255
		|| map_data->f_green < 0 || map_data->f_green > 255
		|| map_data->c_blue < 0 || map_data->f_blue > 255)
			wrong_map_exit(map_data, 21);
}
