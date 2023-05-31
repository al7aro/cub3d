/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:23:44 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 01:30:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "reader.h"
#include "cub3d.h"
#include "hook.h"

void	l(void)
{
	system("leaks cub3d");
}

void	mlx_setup(t_scene *scene)
{
	scene->mlx->mlx = mlx_init();
	scene->mlx->win[RAYS] = mlx_new_window(scene->mlx->mlx,
			scene->mlx->img[RAYS].res.x, scene->mlx->img[RAYS].res.y, "raycasting");
	scene->mlx->win[SCENE] = mlx_new_window(scene->mlx->mlx,
			scene->mlx->img[SCENE].res.x, scene->mlx->img[SCENE].res.y, "cub3d");
	scene->mlx->img[SCENE].img = mlx_new_image(scene->mlx->mlx,
			scene->mlx->img[SCENE].res.x, scene->mlx->img[SCENE].res.y);
	scene->mlx->img[RAYS].img = mlx_new_image(scene->mlx->mlx,
			scene->mlx->img[RAYS].res.x, scene->mlx->img[RAYS].res.y);
	scene->mlx->img[SCENE].addr = mlx_get_data_addr(scene->mlx->img[SCENE].img,
			&scene->mlx->img[SCENE].bpp,
			&scene->mlx->img[SCENE].line_size,
			&scene->mlx->img[SCENE].endian);
	scene->mlx->img[RAYS].addr = mlx_get_data_addr(scene->mlx->img[RAYS].img,
			&scene->mlx->img[RAYS].bpp,
			&scene->mlx->img[RAYS].line_size,
			&scene->mlx->img[RAYS].endian);
}

int	clean_exit(void *scene_void)
{
	t_scene	*scene;

	scene = (t_scene *)scene_void;
	scene_clean(scene);
	exit(0);
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
	printf("\n~mlx_loop running~\n");
	mlx_hook(scene.mlx->win[SCENE], 17, 0, clean_exit, &scene);
	mlx_hook(scene.mlx->win[RAYS], 17, 0, clean_exit, &scene);
	mlx_loop_hook(scene.mlx->mlx, on_loop, &scene);
	mlx_loop(scene.mlx->mlx);
	scene_clean(&scene);
	return (0);
}
