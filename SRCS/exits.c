/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:57:59 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/13 09:53:50 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocation_exit(t_data *map_data)
{
	perror("Allocation Error\n");
	// system("leaks cub3D");
	exit (1);
}

void	wrong_argument_exit(t_data *map_data, int error_code)
{
	if (error_code == 10)
		perror("Wrong Argument Error\n");
	else if (error_code == 11)
		perror("The Map Name is Invalid Error\n");

	// system("leaks cub3D");
	exit (error_code);
}

void	wrong_map_exit(t_data *map_data, int code)
{
	if (code == 20)
		perror("Wrong Or Missing Data in .cub File Error\n");
	else if (code == 21)
		perror("Wrong RGB value Error\n");
	else if (code == 22)
		perror("Empty Line In The Map Or Extra Data Error\n");
	else if (code == 23)
		perror("Wrong Texture File Name Error\n");
	else if (code == 24)
		perror("Wrong Character In Line Error\n");
	else if (code == 25)
		perror("Wrong Character In The Map Error\n");
	else if (code == 26)
		perror("Multiple Starting Point Error\n");
	else if (code == 27)
		perror("There Is No Starting Point In The Map Error\n");
	else if (code == 28)
		perror("Map Must Be Covered By Walls Correctly Error\n");
	else if (code == 29)
		perror("Wrong Texture File Error\n");
	// system("leaks cub3D");
	exit(code);
}

void	free_double_char(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr[i]);
	free(ptr);
}
