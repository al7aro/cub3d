/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:12:11 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/06 23:11:03 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	render_scene(t_scene *scene, int type)
{
	t_img	*img;

	img = &scene->mlx->img[type];
	draw_background(img, rbg_to_int(255, 255, 255));
	draw_rect(img, (t_rect){50, 50, 50, 50}, rbg_to_int(255, 50, 100));
	draw_rect_border(img, (t_rect){50, 50, 50, 50}, 5, rbg_to_int(0, 0, 0));
	draw_circle(img, (t_vec2){200, 200}, 50, rbg_to_int(255, 50, 100));
	draw_line(img, (t_line){0, 0, 500, 500}, 5, rbg_to_int(0, 0, 0));
	return (0);
}

int	on_loop(t_scene *scene)
{
	render_scene(scene, SCENE);
	render_minimap(scene, MINIMAP);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->win[SCENE],
		scene->mlx->img[SCENE].img, 0, 0);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->win[MINIMAP],
		scene->mlx->img[MINIMAP].img, 0, 0);
	return (0);
}
