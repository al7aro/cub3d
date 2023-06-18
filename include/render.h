/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:08:46 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 13:02:57 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "mlx.h"
# include "color.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_rect
{
	double	x;
	double	y;
	double	w;
	double	h;
}				t_rect;

typedef struct s_line
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	pixels;
}				t_line;

typedef struct s_img t_img;
typedef struct s_scene t_scene;
typedef struct s_ray t_ray;

int	on_loop(t_scene *s);

/* Shapes */
int		draw_point(t_img *img, t_vec2 pos, int c);
int		draw_point_novector(t_img *img,	int x, int y, int c);
int		draw_rect(t_img *img, t_rect r, int c);
int		draw_rect_border(t_img *img, t_rect r, int c);
int		draw_circle(t_img *img, t_vec2 pos, int r, int c);
int		draw_background(t_img *img, int c);
int		draw_line(t_img *img, t_line l, int c);

/* Render */
int		render_minimap(t_scene *s, int type);

/* raycast */
int	calculate_rays(t_scene *s, t_img *img);

/* horizontal_ray */
void	horizontal_ray(t_scene *s, t_ray *ray);

/* vertical_ray */
void	vertical_ray(t_scene *s, t_ray *ray);

/* ray_utils */
float	angle_fov(double angle);
void	set_ray_directions(t_ray *ray);
int		ray_beetween_limits(t_scene *s, double h_dist, double v_dist);
int		hits_walll(t_scene *s, double h_dist, double v_dist);
double	distance(double x_start, double y_start, double x_end, double y_end);

#endif
