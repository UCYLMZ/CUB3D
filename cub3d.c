/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:59:07 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/10/24 17:05:40 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*map_data;

	if (ac != 2)
	{
		perror("Wrong Argument Count!\n");
		return (1);
	}
	map_data = malloc(sizeof(t_data));
	if (!map_data)
	{
		perror("Allocation Error!\n");
		return (3);
	}
	map_data->map_name = av[1];
	check_map(map_data);
	return (0);
}