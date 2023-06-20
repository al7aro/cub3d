/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:38:35 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/09 12:38:38 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	intersection(t_scene *s, t_ray *ray)
{
	int	player_x;
	int	player_y;

	player_x = s->player.pos.x;
	player_y = s->player.pos.y;
	if (ray->wall_hit_hor)
		ray->hor_dist = distance(player_x, player_y,
				ray->wall_x_hit_hor, ray->wall_y_hit_hor);
	if (ray->wall_hit_ver)
		ray->ver_dist = distance(player_x, player_y,
				ray->wall_x_hit_ver, ray->wall_y_hit_ver);
	if (ray->hor_dist > ray->ver_dist)
	{
		ray->wall_x_hit = ray->wall_x_hit_ver;
		ray->wall_y_hit = ray->wall_y_hit_ver;
		ray->wall_hit_hor = 0;
	}
	else
	{
		ray->wall_x_hit = ray->wall_x_hit_hor;
		ray->wall_y_hit = ray->wall_y_hit_hor;
		ray->wall_hit_ver = 0;
	}
}

void	dda(t_scene *s, t_ray *ray)
{
	horizontal_ray(s, ray);
	vertical_ray(s, ray);
	intersection(s, ray);
}

void	throw_ray(t_ray *ray, t_scene *scene, double angle)
{
	ray->angle = angle;
	set_ray_directions(ray);
	dda(scene, ray);
}

int	malloc_ray(t_ray **ray_aux)
{
	(*ray_aux) = (t_ray *)malloc(sizeof(t_ray));
	if ((*ray_aux) == NULL)
		return (-1);
	(*ray_aux)->line = (t_line *)malloc(sizeof(t_line));
	if ((*ray_aux)->line == NULL)
		return (-1);
	return (0);
}

int	calculate_rays(t_scene *scene, t_img *img)
{
	t_ray	**ray;
	t_ray	*ray_aux;
	double	angle;
	int		x;

	ray_aux = NULL;
	ray = scene->ray;
	angle = angle_fov(scene->player.dir.x - (FOV / 2));
	clean_prev_ray(scene->ray);
	ray = (t_ray **)malloc(sizeof(t_ray *) * SCENE_WIDTH);
	if (ray == NULL)
		return (-1);
	x = -1;
	while (++x < SCENE_WIDTH)
	{
		if (malloc_ray(&ray_aux) == -1)
			return (-1);
		init_ray(ray_aux);
		throw_ray(ray_aux, scene, angle);
		calculate_hight(ray_aux, x, angle);
		cielling_floor(scene, img, ray_aux);
		draw_wall(img, ray_aux);
		angle = angle_fov(angle + (FOV / SCENE_WIDTH));
	}
	return (0);
}
