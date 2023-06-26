/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:03:56 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/21 22:11:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Res */
# define SCENE_WIDTH 800
# define SCENE_HEIGHT 800
// # define MINIMAP_WIDTH 500
// # define MINIMAP_HEIGHT 200
# define TILE_SIZE 1000
# define MAP_TILE_SIZE 5

/* # define MAP_LIMIT_X SCENE_WIDTH / MAP_TILE_SIZE */
# define MAP_LIMIT_X 160
/* # define MAP_LIMIT_Y SCENE_HEIGHT / MAP_TILE_SIZE */
# define MAP_LIMIT_Y 160

/*# define FOV 60 * (M_PI / 180)*/
# define FOV 1.047197551

/* Tex Indices */
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define ANIMTAION_SIZE 16

/* Color Indices */
# define FLOOR 0
# define CIELLING 1

/* Windows Indices */
# define WINDOWS_NUM 2
# define SCENE 0
# define MINIMAP 1

/* Player */
/*# define PLAYER_SPEED (0.35 * TILE_SIZE)*/
# define PLAYER_SPEED 350
/*# define ROTATION_SPEED 12 * (M_PI / 180)*/
# define ROTATION_SPEED 0.1745329252

# include "math_cub.h"
# include "render.h"

typedef struct s_img
{
	t_vec2	res;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img[WINDOWS_NUM];
}				t_mlx;

typedef struct s_tex
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		w;
	int		h;
	int		anim_size;
}			t_tex;

typedef struct s_player
{
	t_vec2	dir;
	t_vec2	pos;
}				t_player;

typedef struct s_line	t_line;

typedef struct s_ray
{
	float		angle;
	int			is_up;
	int			is_down;
	int			is_left;
	int			is_right;
	double		ver_x_step;
	double		ver_y_step;
	double		hor_x_step;
	double		hor_y_step;
	int			wall_hit_hor;
	double		wall_x_hit_hor;
	double		wall_y_hit_hor;
	int			wall_hit_ver;
	double		wall_x_hit_ver;
	double		wall_y_hit_ver;
	double		wall_x_hit;
	double		wall_y_hit;
	double		hor_dist;
	double		ver_dist;
	t_line		*line;
	double		percert_x;
	double		percert_y;

}				t_ray;

typedef struct s_scene
{
	t_mlx		*mlx;
	t_tex		tex[4];
	long int	anim_current;
	long int	time_sim;
	int			col[2];
	char		**map;
	t_vec2		map_size;
	t_player	player;
	t_ray		**ray;
	char		render_minimap;
	char		map_error_aux;
}				t_scene;

int	clean_exit(void *scene_void);

#endif
