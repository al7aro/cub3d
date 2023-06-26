/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:52:42 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/10 11:52:43 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	vertical_intersections(t_scene *s, t_ray *ray,
	double *ver_x_dist, double *ver_y_dist)
{
	double	inter_y;
	double	inter_x;

	inter_x = floor(s->player.pos.x / TILE_SIZE) * TILE_SIZE;
	if (!ray->is_left)
		inter_x += TILE_SIZE;
	inter_y = s->player.pos.y + ((inter_x - s->player.pos.x) * tan(ray->angle));
	ray->ver_x_step = TILE_SIZE;
	if (ray->is_left)
		ray->ver_x_step *= -1;
	ray->ver_y_step = TILE_SIZE * tan(ray->angle);
	if (!ray->is_down && ray->ver_y_step > 0)
		ray->ver_y_step *= -1;
	if (ray->is_down && ray->ver_y_step < 0)
		ray->ver_y_step *= -1;
	*ver_x_dist = inter_x;
	*ver_y_dist = inter_y;
}

void	vertical_rar_right(t_scene *s, t_ray *ray,
	double *ver_x_dist, double *ver_y_dist)
{
	if (ray->is_left)
		return ;
	while (ray_beetween_limits(s, *ver_x_dist, *ver_y_dist))
	{
		if (hits_walll(s, (*ver_x_dist) + 1, *ver_y_dist))
		{
			ray->wall_hit_ver = 1;
			ray->wall_x_hit_ver = *ver_x_dist;
			ray->wall_y_hit_ver = *ver_y_dist;
			return ;
		}
		else
		{
			*ver_x_dist += ray->ver_x_step;
			*ver_y_dist += ray->ver_y_step;
		}
	}
	if (ray->wall_hit_ver == 0)
	{
		ray->wall_x_hit_ver = *ver_x_dist;
		ray->wall_y_hit_ver = *ver_y_dist;
	}
}

void	vertical_rar_left(t_scene *s, t_ray *ray,
	double *ver_x_dist, double *ver_y_dist)
{
	if (ray->is_right)
		return ;
	while (ray_beetween_limits(s, *ver_x_dist, *ver_y_dist))
	{
		if (hits_walll(s, (*ver_x_dist) - 1, *ver_y_dist))
		{
			ray->wall_hit_ver = 1;
			ray->wall_x_hit_ver = *ver_x_dist;
			ray->wall_y_hit_ver = *ver_y_dist;
			return ;
		}
		else
		{
			*ver_x_dist += ray->ver_x_step;
			*ver_y_dist += ray->ver_y_step;
		}
	}
	if (ray->wall_hit_ver == 0)
	{
		ray->wall_x_hit_ver = *ver_x_dist;
		ray->wall_y_hit_ver = *ver_y_dist;
	}
}

void	vertical_ray(t_scene *s, t_ray *ray)
{
	double	ver_x_dist;
	double	ver_y_dist;

	vertical_intersections(s, ray, &ver_x_dist, &ver_y_dist);
	vertical_rar_right(s, ray, &ver_x_dist, &ver_y_dist);
	vertical_rar_left(s, ray, &ver_x_dist, &ver_y_dist);
}
