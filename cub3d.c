/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:59:07 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/10/31 17:24:03 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	int i = -1;
	printf("map:\n");
	while (map_data->map[++i])
		printf("%s", map_data->map[i]);
	printf("\nw:%s\ne:%s\nn:%s\ns:%s\n\n",
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
	return (0);
}
