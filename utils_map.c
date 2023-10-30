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