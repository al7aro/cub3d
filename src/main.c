/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:23:44 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 22:26:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "reader_map.h"
#include "cub3d.h"
#include "scene_utils.h"

#define WIDTH 600
#define HEIGHT 600

void	l(void)
{
	system("leaks cub3d");
}

void	mlx_setup(t_scene *scene)
{
	scene->mlx->mlx = mlx_init();
	scene->mlx->win[SCENE] = mlx_new_window(scene->mlx->mlx,
			WIDTH, HEIGHT, "cub3d");
	scene->mlx->win[RAYS] = mlx_new_window(scene->mlx->mlx,
			WIDTH, HEIGHT, "raycasting");
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	atexit(l);
	if (argc != 2)
		return (-1);
	scene_setup(&scene);
	if (OK != reader(&scene, *(argv + 1)))
	{
		scene_clean(&scene);
		return (-1);
	}
	mlx_setup(&scene);
	mlx_put_image_to_window(scene.mlx->mlx, scene.mlx->win[SCENE],
		scene.tex[NORTH].img, 0, 0);
	mlx_put_image_to_window(scene.mlx->mlx, scene.mlx->win[RAYS],
		scene.tex[EAST].img, 0, 0);
	printf("\n~mlx_loop running~\n");
	// mlx_loop(scene.mlx->mlx);
	scene_clean(&scene);
	return (0);
}
