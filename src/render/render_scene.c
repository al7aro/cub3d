/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:08:34 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 00:09:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	shade_scene(t_scene *scene, int x, int y)
{
	double	_x, _y, eps = 0.1;
	_x = 4.0 * (double)x / scene->mlx->img[SCENE].res.x - 2.0;
	_y = 4.0 * (double)y / scene->mlx->img[SCENE].res.y - 2.0;
	if (_x * _x * _x > _y - eps && _x * _x * _x < _y + eps)
		return (rbg_to_int(200, 200, 200));
	else
		return (rbg_to_int(240, 45, 125));
}
