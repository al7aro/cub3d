/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:08:46 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/09 13:18:30 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "mlx.h"
# include "color.h"
# include <math.h>
# include <stdlib.h>

typedef struct t_rect
{
	int	x;
	int	y;
	int	w;
	int	h;
}				t_rect;

typedef struct t_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}				t_line;

int	on_loop(t_scene *s);

/* Shapes */
int	draw_point(t_img *img, t_ivec2 pos, int c);
int	draw_rect(t_img *img, t_rect r, int c);
int	draw_rect_border(t_img *img, t_rect r, int weight, int c);
int	draw_circle(t_img *img, t_ivec2 pos, int r, int c);
int	draw_background(t_img *img, int c);
int	draw_line(t_img *img, t_line l, int weight, int c);

/* Render */
int	render_minimap(t_scene *s, int type);

#endif
