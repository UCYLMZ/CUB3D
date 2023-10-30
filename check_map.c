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

void	map_multiply(t_data *map_data, int first, int second)
{
	int	i;

	map_data->map = malloc(sizeof(char *) * (second - first));
	if (!map_data->map)
		allocation_exit(map_data);
	i = -1;
	printf("first:%d\nsecond%d\n", first, second);
	while (++first < second)
	{
		printf("line: %s", map_data->whole_map[first]);
		map_data->map[++i] = ft_strdup(map_data->whole_map[first]);
	}
	map_data->map[i] = NULL;
}

void	map_itself(t_data *map_data, int first_space)
{
	int	i;
	int	second_space;

	i = -1;
	while (++i < map_data->line_count)
	{
		if (map_data->whole_map[i][0] == ' ')
		{
			second_space = i;
			while (map_data->whole_map[i][0] == ' ')
				i++;
		}
		if (map_data->whole_map[i] == NULL)
		{
			second_space = i;
			map_multiply(map_data, first_space, second_space);
		}
		else
			wrong_map_exit(map_data);
	}
}

void	get_infos(t_data *map_data, char **whole_map)
{
	int	i;

	i = -1;
	while (++i < map_data->line_count)
	{
		if (whole_map[i][0] == 'N')
			map_data->north = ft_strdup(whole_map[i]);
		else if (whole_map[i][0] == 'S')
			map_data->south = ft_strdup(whole_map[i]);
		else if (whole_map[i][0] == 'W')
			map_data->west = ft_strdup(whole_map[i]);
		else if (whole_map[i][0] == 'E')
			map_data->east = ft_strdup(whole_map[i]);
		else if (whole_map[i][0] == 'F')
			map_data->floor = ft_strdup(whole_map[i]);
		else if (whole_map[i][0] == 'C')
			map_data->ceiling = ft_strdup(whole_map[i]);
		else if (whole_map[i][0] == ' ')
			map_itself(map_data, i);
		else
			wrong_map_exit(map_data);
	}
}

void	get_map(t_data *map_data)
{
	int	i;
	int	fd;

	map_data->line_count = get_line_count(map_data);
	map_data->whole_map = malloc(sizeof(char *) * (map_data->line_count + 1));
	if (!(map_data->whole_map))
		allocation_exit(map_data);
	fd = open(map_data->map_path, O_RDONLY);
	if (fd < 0)
		wrong_argument_exit(map_data, 2);
	i = -1;
	while (++i < map_data->line_count)
		map_data->whole_map[i] = get_next_line(fd);
	map_data->whole_map[i] = NULL;
}

void	check_map(t_data *map_data)
{
	get_map(map_data);
	get_infos(map_data, map_data->whole_map);
}