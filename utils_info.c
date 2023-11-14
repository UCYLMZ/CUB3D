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

char	*get_path(char *trimmed)
{
	int	i;

	i = -1;
	while (trimmed[++i] != '.' && trimmed[i] && trimmed[i + 1] != '/')
	{
		if (!trimmed[i])
			break ;
	}
	return (ft_strdup(&trimmed[i]));
}

void	get_textures(t_data *map_data, char *trimmed)
{
	int		i;
	int		flag;
	char	**splitted;

	flag = 0;
	splitted = ft_split_special(trimmed);
	if (!splitted[1])
	{
		free_double_char(splitted);
		wrong_map_exit(map_data, 23);
	}
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
	free_double_char(splitted);
	if (flag == 1)
		wrong_map_exit(map_data, 20);
}

void	set_ceiling_floor(t_data *map_data, char **splitted, int flag)
{
	int	count;

	count = 0;
	if (flag == 1)
	{
		free_double_char(splitted);
		wrong_map_exit(map_data, 21);
	}
	while (splitted[count] != NULL)
		count++;
	if (splitted[0][0] == 'F' && count == 4)
	{
		map_data->f_red = ft_atoi(splitted[1]);
		map_data->f_green = ft_atoi(splitted[2]);
		map_data->f_blue = ft_atoi(splitted[3]);
	}
	else if (splitted[0][0] == 'C' && count == 4)
	{
		map_data->c_red = ft_atoi(splitted[1]);
		map_data->c_green = ft_atoi(splitted[2]);
		map_data->c_blue = ft_atoi(splitted[3]);
	}
	else
		wrong_map_exit(map_data, 21);
}

void	get_ceiling_floor(t_data *map_data, char *trimmed)
{
	int		i;
	int		j;
	int		flag;
	char	**splitted;

	flag = 0;
	splitted = ft_split_special(trimmed);
	i = 0;
	while (splitted[++i])
	{
		if (flag == 1)
			break ;
		j = 0;
		while (splitted[i][j])
		{
			if ((!ft_isdigit(splitted[i][j]) || i > 3))
			{
				flag = 1;
				break ;
			}
			j++;
		}
	}
	set_ceiling_floor(map_data, splitted, flag);
	free_double_char(splitted);
}
