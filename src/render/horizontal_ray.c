/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:52:22 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/10 11:52:24 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	horizontal_intersections(t_scene *s, t_ray *ray,
	double *hor_x_dist, double *hor_y_dist)
{
	double	inter_y;
	double	inter_x;

	inter_y = floor(s->player.pos.y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_down)
		inter_y += TILE_SIZE;
	inter_x = s->player.pos.x + ((inter_y - s->player.pos.y) / tan(ray->angle));
	ray->hor_y_step = TILE_SIZE;
	if (!ray->is_down)
		ray->hor_y_step *= -1;
	ray->hor_x_step = TILE_SIZE / tan(ray->angle);
	if (ray->is_left && ray->hor_x_step > 0)
		ray->hor_x_step *= -1;
	if (!ray->is_left && ray->hor_x_step < 0)
		ray->hor_x_step *= -1;
	*hor_x_dist = inter_x;
	*hor_y_dist = inter_y;
}

void	horizontal_ray_up(t_scene *s, t_ray *ray,
	double *hor_x_dist, double *hor_y_dist)
{
	if (ray->is_down)
		return ;
	while (ray_beetween_limits(s, *hor_x_dist, (*hor_y_dist)))
	{
		if (hits_walll(s, *hor_x_dist, (*hor_y_dist) - 1))
		{
			ray->wall_hit_hor = 1;
			ray->wall_x_hit_hor = *hor_x_dist;
			ray->wall_y_hit_hor = (*hor_y_dist);
			return ;
		}
		else
		{
			*hor_x_dist += ray->hor_x_step;
			(*hor_y_dist) += ray->hor_y_step;
		}
	}
	if (ray->wall_hit_hor == 0)
	{
		ray->wall_x_hit_hor = *hor_x_dist;
		ray->wall_y_hit_hor = (*hor_y_dist);
	}
}

void	horizontal_ray_down(t_scene *s, t_ray *ray,
	double *hor_x_dist, double *hor_y_dist)
{
	if (ray->is_up)
		return ;
	while (ray_beetween_limits(s, *hor_x_dist, (*hor_y_dist)))
	{
		if (hits_walll(s, *hor_x_dist, ((*hor_y_dist)) + 1))
		{
			ray->wall_hit_hor = 1;
			ray->wall_x_hit_hor = *hor_x_dist;
			ray->wall_y_hit_hor = (*hor_y_dist);
			return ;
		}
		else
		{
			*hor_x_dist += ray->hor_x_step;
			(*hor_y_dist) += ray->hor_y_step;
		}
	}
	if (ray->wall_hit_hor == 0)
	{
		ray->wall_x_hit_hor = *hor_x_dist;
		ray->wall_y_hit_hor = (*hor_y_dist);
	}
}

void	horizontal_ray(t_scene *s, t_ray *ray)
{
	double	hor_x_dist;
	double	hor_y_dist;

	horizontal_intersections(s, ray, &hor_x_dist, &hor_y_dist);
	horizontal_ray_up(s, ray, &hor_x_dist, &hor_y_dist);
	horizontal_ray_down(s, ray, &hor_x_dist, &hor_y_dist);
}
