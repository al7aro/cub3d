/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:44:39 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/19 12:08:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	texture_get_color(t_tex tex, t_ivec2 pos)
{
	return (*(unsigned int *)(tex.addr + (pos.x * (tex.bpp / 8)
		+ pos.y * tex.len)));
}

int	texture_vline(t_scene *s, t_ray *ray, int orientation)
{
	t_tex	tex;
	int		col;
	int		i;
	double	y_p;
	double	perc;

	i = ray->line->y0;
	tex = s->tex[orientation];
	perc = ray->percert_y;
	if (SOUTH == orientation || NORTH == orientation)
		perc = ray->percert_x;
	while (i < ray->line->y1)
	{
		y_p = (((double)(i - ray->line->y0) / (double)(ray->line->y1 - ray->line->y0)));
		col = texture_get_color(tex, (t_ivec2){.x = perc * (double)tex.w,
			.y =  y_p * (double)tex.h});
		draw_point_novector(&s->mlx->img[SCENE], ray->line->x0, i, col);
		i++;
	}
	return 0;
}