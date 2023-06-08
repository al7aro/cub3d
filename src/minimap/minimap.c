/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:10:55 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/06 23:51:31 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

int	render_minimap(t_scene *scene, int type)
{
	t_img	*img;
	int		i;
	int		j;

	j = 0;
	img = &scene->mlx->img[type];
	draw_background(img, rbg_to_int(255, 255, 255));
	while (j < scene->map_size.y)
	{
		i = 0;
		while (i < scene->map_size.x)
		{
			if (scene->map[j][i] == '1')
			{
				draw_rect(img, (t_rect){i * TILE_SIZE, j * TILE_SIZE,
					TILE_SIZE, TILE_SIZE}, rbg_to_int(255, 0, 0));
				draw_rect_border(img, (t_rect){i * TILE_SIZE, j * TILE_SIZE,
					TILE_SIZE, TILE_SIZE}, 3, rbg_to_int(0, 0, 0));
			}
			i++;
		}
		j++;
	}
	draw_circle(img, scene->player.pos, 7, rbg_to_int(0, 255, 0));
	draw_circle(img, (t_vec2){scene->player.pos.x + scene->player.dir.x * 8,
		scene->player.pos.y + scene->player.dir.y * 8}, 5, rbg_to_int(0, 0, 0));
	return (0);
}
