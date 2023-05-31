/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:03:56 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 22:25:05 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Tex Indices */
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

/* Color Indices */
# define FLOOR 0
# define CIELLING 1

/* Windows Indices */
# define SCENE 0
# define RAYS 1

# include "math_cub.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win[2];
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
}			t_tex;

typedef struct s_player
{
	t_vec2	dir;
}				t_player;

typedef struct s_scene
{
	t_mlx		*mlx;
	t_tex		tex[4];
	int			col[2];
	char		**map;
	t_vec2		map_size;
	t_player	player;
}				t_scene;

#endif
