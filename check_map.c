/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:12:39 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/10/25 16:19:27 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_line_count(t_data *map_data)
{
	int		fd;
	int		count;
	char	*line;
	char	*map1;
	
	map1 = ft_strjoin("MAPS", "/");
	map_data->map_path = ft_strjoin(map1, map_data->map_name);
	if (!map1 || !map_data->map_path)
		allocation_exit(map_data);
	if (map1)
		free(map1);
	fd = open(map_data->map_path, O_RDONLY);
	if (fd < 0)
		wrong_argument_exit(map_data, 2);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);	
	}
	close(fd);
	free(line);
	return (count);
}

char	**get_map(t_data *map_data)
{
	map_data->line_count = get_line_count(map_data);
	map_data->whole_map = malloc(sizeof(char *) * (map_data->line_count + 1));
	if (!(map_data->whole_map))
		allocation_exit(map_data);
	// int i = -1;
	// while ((map_data->whole_map)[++i])
	// 	printf("%s", (map_data->whole_map)[i]);
}

void	check_map(t_data *map_data)
{
	map_data->whole_map = get_map(map_data);
}