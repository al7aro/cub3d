/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:12:11 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 00:41:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "stdio.h"

int	pixel_buffer_put(t_img *img, int x, int y, int c)
{
	int	first_char;

	first_char = x * (img->bpp / 8) + y * img->line_size;
	*(img->addr + first_char + 0) = (char)((c & 0x000000FF) >> 0);
	*(img->addr + first_char + 1) = (char)((c & 0x0000FF00) >> 8);
	*(img->addr + first_char + 2) = (char)((c & 0x00FF0000) >> 16);
	*(img->addr + first_char + 3) = (char)((c & 0xFF000000) >> 24);
	return (0);
}

void	render(t_scene *scene, int type)
{
	int		x;
	int		y;
	int		y_limit;
	int		x_limit;
	t_img	*img;

	img = &scene->mlx->img[type];
	y = -1;
	y_limit = img->res.y;
	x_limit = img->res.x;
	while (++y < y_limit)
	{
		x = -1;
		while (++x < x_limit)
		{
			if (type == SCENE)
				pixel_buffer_put(img, x, y, shade_scene(scene, x, y));
			else if (type == RAYS)
				pixel_buffer_put(img, x, y, shade_rays(scene, x, y));
		}
	}
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->win[type], img->img, 0, 0);
}
