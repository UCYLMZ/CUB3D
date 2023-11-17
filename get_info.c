/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:31:17 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/11/14 14:04:10 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_info(t_data *map_data, char *line)
{
	int		i;
	char	*trimmed;

	i = 0;
	while (is_it_ws(line[i]))
		i++;
	trimmed = ft_strdup(&line[i]);
	if ((trimmed[0] == 'C' || trimmed[0] == 'F') && map_data->floor == NULL
		&& (trimmed[1] == ' ' && map_data->ceiling == NULL))
		get_ceiling_floor(map_data, trimmed);
	else if (((trimmed[0] == 'E' && trimmed[1] == 'A' && map_data->east == NULL)
			|| (trimmed[0] == 'W' && trimmed[1] == 'E' && map_data->west == NULL)
			|| (trimmed[0] == 'N' && trimmed[1] == 'O' && map_data->north == NULL)
			|| (trimmed[0] == 'S' && trimmed[1] == 'O' && map_data->south == NULL))
		&& is_it_ws(trimmed[2]))
		get_textures(map_data, trimmed);
	else
	{
		free(trimmed);
		wrong_map_exit(map_data, 20);
	}
	free(trimmed);
	free(line);
}

void	get_info(t_data *map_data, int flag, char **new_map)
{
	int	i;
	int	j;

	free_double_char(map_data->whole_map);
	map_data->whole_map = new_map;
	if (flag == 2)
	{
		free_double_char(map_data->whole_map);
		wrong_map_exit(map_data, 22);
	}
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

void	set_clean_map(t_data *map_data, char **new_map, int count)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = 0;
	flag = 0;
	while (map_data->whole_map[++i])
	{
		if (j > 6 && is_line_empty(map_data->whole_map[i]))
			flag = 1;
		if (!is_line_empty(map_data->whole_map[i]))
		{
			if (flag == 1)
			{
				flag = 2;
				break ;
			}
			new_map[j++] = ft_strdup(map_data->whole_map[i]);
		}
	}
	get_info(map_data, flag, new_map);
}

void	clear_map(t_data *map_data)
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
}
