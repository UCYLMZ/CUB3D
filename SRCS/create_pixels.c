/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:17:28 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/12/13 10:17:29 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->data + (y * image->sizeline + x * (image->bpp / 8));
	*(int *)pixel = color;
}

unsigned int	get_pixel_in_texture(t_texture *texture, int x, int y)
{
	char	*re;

	re = texture->data + (y * texture->sizeline + x * (texture->bpp / 8));
	return (*((unsigned int *)re));
}
