/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:02:19 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/20 12:24:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	calculate_hight(t_ray *ray, int column, double angle)
{
	double		wall_height;
	double		fish_eye;

	if (ray->wall_hit_ver)
		fish_eye = (ray->ver_dist / TILE_SIZE) * cos(angle - ray->angle);
	else
		fish_eye = (ray->hor_dist / TILE_SIZE) * cos(angle - ray->angle);
	wall_height = ((SCENE_WIDTH / 2) / tan(FOV / 2)) / fish_eye;
	ray->line->x0 = column;
	ray->line->y0 = (SCENE_HEIGHT / 2) - (wall_height / 2);
	if (ray->line->y0 < 0)
		ray->line->y0 = 0;
	ray->line->x1 = column;
	ray->line->y1 = (SCENE_HEIGHT / 2) + (wall_height / 2);
	if (ray->line->y1 >= SCENE_HEIGHT)
		ray->line->y1 = SCENE_HEIGHT - 1;
}

void	init_ray(t_ray *ray)
{
	ray->angle = 0;
	ray->is_up = 0;
	ray->is_down = 0;
	ray->is_left = 0;
	ray->is_right = 0;
	ray->ver_x_step = 0;
	ray->ver_y_step = 0;
	ray->hor_x_step = 0;
	ray->hor_y_step = 0;
	ray->wall_hit_hor = 0;
	ray->wall_hit_ver = 0;
	ray->wall_x_hit_hor = 0;
	ray->wall_y_hit_hor = 0;
	ray->wall_x_hit_ver = 0;
	ray->wall_y_hit_ver = 0;
	ray->wall_x_hit = 0;
	ray->wall_y_hit = 0;
	ray->hor_dist = INT_MAX;
	ray->ver_dist = INT_MAX;
}

void	clean_prev_ray(t_ray **ray)
{
	int	i;

	i = -1;
	if (ray != NULL)
	{
		while (++i < SCENE_WIDTH)
		{
			if (ray[i] != NULL && ray[i]->line != NULL)
			{
				free(ray[i]->line);
				ray[i]->line = NULL;
			}
			free(ray[i]);
			ray[i] = NULL;
		}
		ray = NULL;
	}
}

void	cielling_floor(t_scene *scene, t_img *img, t_ray *ray_aux)
{
	t_line	line_sky;

	line_sky.x0 = ray_aux->line->x0;
	line_sky.y0 = -1;
	line_sky.x1 = ray_aux->line->x1;
	line_sky.y1 = SCENE_HEIGHT / 2;
	draw_line(img, line_sky, scene->col[CIELLING]);
	line_sky.y0 = SCENE_HEIGHT / 2;
	line_sky.y1 = SCENE_HEIGHT;
	draw_line(img, line_sky, scene->col[FLOOR]);
}

void	draw_wall(t_scene *scene, t_ray *ray_aux)
{
	ray_aux->percert_x = (ray_aux->wall_x_hit / TILE_SIZE)
		- floor(ray_aux->wall_x_hit / TILE_SIZE);
	ray_aux->percert_y = (ray_aux->wall_y_hit / TILE_SIZE)
		- floor(ray_aux->wall_y_hit / TILE_SIZE);
	if (ray_aux->wall_hit_hor)
	{
		if (ray_aux->is_up)
			texture_vline(scene, ray_aux, NORTH);
		else
			texture_vline(scene, ray_aux, SOUTH);
	}
	else
	{
		if (ray_aux->is_left)
			texture_vline(scene, ray_aux, WEST);
		else
			texture_vline(scene, ray_aux, EAST);
	}
}
