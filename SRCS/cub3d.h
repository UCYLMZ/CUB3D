/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:24:18 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/04 16:07:25 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "mlx/mlx.h"
# include "LIBFT/libft.h"
# include "GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>
# include <stdio.h> //! sil!!!

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
	char	direction;
}	t_data;

typedef struct mlx_data_test
{
    void	*mlx;
    void	*win;
}	m_data;

void	check_map(t_data *map_data);
void	allocation_exit(t_data *map_data);
void	wrong_argument_exit(t_data *map_data, int error_code);
void	wrong_map_exit(t_data *map_data, int code);
int		is_line_empty(char *line);
char	**ft_split_special(const char *s);
void	clear_map(t_data *map_data);
void	get_textures(t_data *map_data, char *trimmed);
void	get_ceiling_floor(t_data *map_data, char *trimmed);
void	free_double_char(char **ptr);
int		is_it_ws(int c);
void	check_rgb(t_data *map_data);
void	check_map_characters(t_data *map_data, char **map);
void	check_borders(t_data *map_data, char **map);
int		create_rgb_color(int red, int green, int blue);
void	draw_fc(m_data *data, t_data *map_data);
void	render();

#endif