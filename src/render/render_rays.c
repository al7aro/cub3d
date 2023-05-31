/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:38:43 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 01:40:13 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	shade_rays(t_scene *scene, int x, int y)
{
	double	_x, _y, eps = 0.2;
	_x = 20.0 * (double)x / scene->mlx->img[RAYS].res.x - 10.0;
	_y = 4.0 * (double)y / scene->mlx->img[RAYS].res.y - 2.0;
	if (sin(_x) > _y - eps && sin(_x) < _y + eps)
		return (rbg_to_int(200, 200, 200));
	else
		return (rbg_to_int(25, 215, 25));
}
