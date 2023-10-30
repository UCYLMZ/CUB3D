#ifndef CUB3D_H
# define CUB3D_H
# include "SRCS/LIBFT/libft.h"
# include "SRCS/GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>
# include <stdio.h> //sil!!!

typedef struct s_data
{
	int		line_count;
	char 	*map_name;
	char	*map_path;
	char 	**whole_map;
	char	**map;
	char	*floor;
	char	*ceiling;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_data;

void	check_map(t_data *map_data);
void	allocation_exit(t_data *map_data);
void	wrong_argument_exit(t_data *map_data, int error_code);
void	wrong_map_exit(t_data *map_data);
int		get_line_count(t_data *map_data);

#endif