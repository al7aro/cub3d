/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:12:11 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/22 23:00:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_map_tile(t_scene *s, t_img *img, int x, int y)
{
	if (s->map[y][x] == '1')
	{
		draw_rect(img, (t_rect){x * MAP_TILE_SIZE, y * MAP_TILE_SIZE,
			MAP_TILE_SIZE, MAP_TILE_SIZE}, rbg_to_int(255, 0, 0));
		draw_rect_border(img,
			(t_rect){x * MAP_TILE_SIZE, y * MAP_TILE_SIZE,
			MAP_TILE_SIZE, MAP_TILE_SIZE}, rbg_to_int(0, 0, 0));
	}
	if (x == 0 || y == 0
		|| x == s->map_size.x - 1 || y == s->map_size.y - 1)
		draw_rect(img, (t_rect){x * MAP_TILE_SIZE, y * MAP_TILE_SIZE,
			MAP_TILE_SIZE, MAP_TILE_SIZE}, rbg_to_int(0, 0, 0));
}

int	render_minimap(t_scene *s, int type)
{
	t_img	*img;
	int		i;
	int		j;
	t_vec2	pos;

	j = -1;
	img = &s->mlx->img[type];
	draw_background(img, rbg_to_int(150, 150, 150));
	while (++j < s->map_size.y)
	{
		i = -1;
		while (++i < s->map_size.x)
			draw_map_tile(s, img, i, j);
	}
	pos = (t_vec2){.x = s->player.pos.x / (TILE_SIZE / MAP_TILE_SIZE),
		.y = s->player.pos.y / (TILE_SIZE / MAP_TILE_SIZE)};
	draw_circle(img, pos, 3, rbg_to_int(0, 255, 0));
	return (0);
}

int	render_scene(t_scene *s, int type)
{
	t_img	*img;

	s->time_sim++;
	img = &s->mlx->img[type];
	draw_background(img, rbg_to_int(255, 255, 255));
	calculate_rays(s, img);
	if (!(s->time_sim % 5))
		s->anim_current++;
	return (0);
}

int	on_loop(t_scene *s)
{
	render_scene(s, SCENE);
	mlx_put_image_to_window(s->mlx->mlx, s->mlx->win,
		s->mlx->img[SCENE].img, 0, 0);
	if (s->render_minimap)
	{
		render_minimap(s, MINIMAP);
		mlx_put_image_to_window(s->mlx->mlx, s->mlx->win,
			s->mlx->img[MINIMAP].img, 0, 0);
	}
	return (0);
}
