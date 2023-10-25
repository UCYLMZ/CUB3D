/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:57:59 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/10/25 16:08:46 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocation_exit(t_data *map_data)
{
	perror("Allocation Error\n");
	exit (3);
}

void	wrong_argument_exit(t_data *map_data, int error_code)
{
	if (error_code == 1)
		perror("Wrong Argument Error\n");
	else if (error_code == 2)
		perror("The Map Name is Invalid Error\n");
	exit (4);
}