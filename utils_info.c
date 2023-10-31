/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:36:48 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/10/31 18:33:31 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

void	get_textures(t_data *map_data, char *trimmed)
{
	int		i;
	int		flag;
	char	**splitted;

	flag = 0;
	splitted = ft_split(trimmed, ' ');
	if (splitted[0][0] == 'E' && splitted[0][1] == 'A')
		map_data->east = ft_strdup(splitted[1]);
	else if (splitted[0][0] == 'W' && splitted[0][1] == 'E')
		map_data->west = ft_strdup(splitted[1]);
	else if (splitted[0][0] == 'N' && splitted[0][1] == 'O')
		map_data->north = ft_strdup(splitted[1]);
	else if (splitted[0][0] == 'S' && splitted[0][1] == 'O')
		map_data->south = ft_strdup(splitted[1]);
	else
		flag = 1;
	i = -1;
	while (splitted[++i])
		free(splitted[i]);
	free(splitted[i]);
	free(splitted);
	if (flag == 1)
		wrong_map_exit(map_data);
}

void	set_ceiling_floor(t_data *map_data)
{
	
}

void	get_ceiling_floor(t_data *map_data, char *trimmed)
{
	int		i;
	int		j;
	int		flag;
	char	**splitted;

	splitted = ft_split(trimmed, ' ');
	i = -1;
	j = 1;
	flag = 0;
	while (splitted[++i])
	{
		if (j > 5)
			break ;
		while (splitted[i][j])
		{
			if (!ft_isdigit(splitted[i][j]))
				flag = 1;
			j += 2;
		}
	}
	if (flag == 1)
		wrong_map_exit(map_data);
	set_ceiling_floor(map_data);
}
