/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:55:52 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/10 11:55:55 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float	angle_fov(double angle)
{
	if (angle >= 2 * M_PI)
		angle -= (2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return ((float)angle);
}

void	set_ray_directions(t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->is_down = 1;
	else
		ray->is_down = 0;
	if (ray->angle > M_PI_2 && ray->angle < (3 * M_PI_2))
		ray->is_left = 1;
	else
		ray->is_left = 0;
	ray->is_up = !ray->is_down;
	ray->is_right = !ray->is_left;
}

int	ray_beetween_limits(t_scene *s, double h_dist, double v_dist)
{
	if (h_dist >= 0 && v_dist >= 0 && 
		h_dist < s->map_size.x * TILE_SIZE && v_dist < s->map_size.y * TILE_SIZE)
		return (1);
	return (0);

}

int	hits_walll(t_scene *s, double h_dist, double v_dist)
{
	int		map_x;
	int		map_y;

	if (ray_beetween_limits(s, h_dist, v_dist) == 0)
		return (1);
	map_x = (int)(h_dist / TILE_SIZE);
	map_y = (int)(v_dist / TILE_SIZE);
	if (map_x >= s->map_size.x * TILE_SIZE)
		return (1);
	if (s->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}