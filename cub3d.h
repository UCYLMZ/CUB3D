/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:24:18 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/10/31 17:24:39 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "SRCS/LIBFT/libft.h"
# include "SRCS/GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>
# include <stdio.h> //sil!!!

typedef struct s_data
{
	int		line_count;
	char	*map_name;
	char	*map_path;
	char	**whole_map;
	char	**map;
	char	*floor;
	int		f_red;
	int		f_green;
	int		f_blue;
	char	*ceiling;
	int		c_red;
	int		c_green;
	int		c_blue;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_data;

void	check_map(t_data *map_data);
void	allocation_exit(t_data *map_data);
void	wrong_argument_exit(t_data *map_data, int error_code);
void	wrong_map_exit(t_data *map_data);
int		is_line_empty(char *line);

#endif