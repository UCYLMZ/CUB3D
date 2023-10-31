/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:31:17 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/10/31 17:25:20 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_info(t_data *map_data, char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " ");
	if ((trimmed[0] == 'C' || trimmed[0] == 'F')
		&& (trimmed[1] == ' ' && map_data->ceiling == NULL))
		get_ceiling_floor(map_data, trimmed);
	else if ((trimmed[0] == 'E' && trimmed[1] == 'A' && map_data->east == NULL)
		|| (trimmed[0] == 'W' && trimmed[1] == 'E' && map_data->west == NULL)
		|| (trimmed[0] == 'N' && trimmed[1] == 'O' && map_data->north == NULL)
		|| (trimmed[0] == 'S' && trimmed[1] == 'O' && map_data->south == NULL))
		get_textures(map_data, trimmed);
	else
	{
		free(trimmed);
		wrong_map_exit(map_data);
	}
	free(trimmed);
}

void	set_clean_map(t_data *map_data, char **new_map, int count)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map_data->whole_map[++i])
	{
		if (!is_line_empty(map_data->whole_map[i]))
			new_map[j++] = ft_strdup(map_data->whole_map[i]);
		free(map_data->whole_map[i]);
	}
	free(map_data->whole_map[i]);
	free(map_data->whole_map);
	map_data->whole_map = new_map;
	i = -1;
	while (++i < 6)
		fill_info(map_data, map_data->whole_map[i]);
	map_data->map = malloc(sizeof(char *) * (map_data->line_count - 6 + 1));
	if (!map_data->map)
		allocation_exit(map_data);
	j = 0;
	while (map_data->whole_map[i])
		map_data->map[j++] = ft_strdup(map_data->whole_map[i++]);
	map_data->map[j] = NULL;
}

void	clean_map(t_data *map_data)
{
	int		i;
	int		count;
	char	**spaceless;

	i = -1;
	count = 0;
	while (++i < map_data->line_count)
	{
		if (!is_line_empty(map_data->whole_map[i]))
			count++;
	}
	map_data->line_count = count;
	spaceless = malloc(sizeof(char *) * (count + 1));
	if (!spaceless)
		allocation_exit(map_data);
	spaceless[count] = NULL;
	set_clean_map(map_data, spaceless, count);
	i = -1;
	while (map_data->map[++i])
		printf("%s", map_data->map[i]);
}

void	get_infos(t_data *map_data, char **whole_map)
{
	clean_map(map_data);
}
