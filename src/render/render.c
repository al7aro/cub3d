/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:12:11 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 13:01:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	render_scene(t_scene *s, int type)
{
	t_img	*img;

	img = &s->mlx->img[type];
	draw_background(img, rbg_to_int(255, 255, 255));
	draw_circle(img, (t_vec2){100, 100}, 50, rbg_to_int(255, 50, 100));
	draw_circle(img, (t_vec2){400, 100}, 50, rbg_to_int(255, 50, 100));
	draw_circle(img, (t_vec2){240, 250}, 10, rbg_to_int(0, 0, 0));
	draw_circle(img, (t_vec2){260, 250}, 10, rbg_to_int(0, 0, 0));
	draw_line(img, (t_line){100, 300, 250, 350}, 5, rbg_to_int(0, 0, 0));
	draw_line(img, (t_line){250, 350, 400, 300}, 5, rbg_to_int(0, 0, 0));
	return (0);
}

int	on_loop(t_scene *s)
{
	render_scene(s, SCENE);
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win[SCENE],
		s->mlx->img[SCENE].img, 0, 0);
	return (0);
}
