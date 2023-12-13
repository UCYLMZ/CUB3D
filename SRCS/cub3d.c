/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:59:07 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/13 05:26:42 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_proc(t_data *data)
{
	player_move(data);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win, data->img.image, 0, 0);
	return (0);
}

int	exit_test()
{
	exit(1);
}

void	start_game(t_data *data)
{
	data->mlx_data->mlx = mlx_init();
	data->mlx_data->win = mlx_new_window(data->mlx_data->mlx, WIDTH, HEIGHT, "Cub3d");
	//start_init(data);
	start_img(data);
	xpm_to_textures(data);
	mlx_hook(data->mlx_data->win, 2, 0, key_press, data);
	mlx_hook(data->mlx_data->win, 3, 0, key_release, data);
	mlx_hook(data->mlx_data->win, 17, 1L << 2, exit_test, data); //! exit fonksiyonu yapilacak
	mlx_loop_hook(data->mlx_data->mlx, &main_proc, data);
	mlx_loop(data->mlx_data->mlx);
}

int	main(int ac, char **av)
{
	t_data	*map_data;

	if (ac != 2)
		wrong_argument_exit(NULL, 10);
	map_data = malloc(sizeof(t_data));
	if (!map_data)
		allocation_exit(map_data);
	map_data->map_name = av[1];
	check_map(map_data);
	printf("\nlinecount:%d\n", map_data->line_count);
	convert_to_int(map_data);

	
	int i = -1;
	printf("map:\n");
	while (map_data->map[++i])
		printf("%s", map_data->map[i]);
	printf("\nw:%s#\ne:%s#\nn:%s#\ns:%s#\n\n",
	map_data->west, map_data->east, map_data->north,map_data->south);
	printf("floor:\n%d %d %d\nceiling:\n%d %d %d\nstarting:%c\n",
	map_data->f_red, 
	map_data->f_green, 
	map_data->f_blue, 
	map_data->c_red, 
	map_data->c_green, 
	map_data->c_blue,
	map_data->direction);
	// system("leaks cub3D");
	//render(map_data);

	map_data->mlx_data = (m_data*)malloc(sizeof(m_data));

	start_game(map_data);
	return (0);
}
