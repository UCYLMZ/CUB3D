#ifndef CUB3D_H
# define CUB3D_H
# include "SRCS/LIBFT/libft.h"
# include "SRCS/GET_NEXT_LINE/get_next_line.h"
# include <fcntl.h>
# include <stdio.h> //sil!!!

typedef struct s_data
{
	char 	*map_name;
	char	*map_path;
	char 	**whole_map;
}	t_data;

void	check_map(t_data *map_data);

#endif