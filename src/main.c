/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:23:44 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 12:18:34 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene_utils.h"
#include "mlx.h"
#include "libft.h"
#include "reader.h"
#include "render.h"
#include "cub3d.h"
#include "hook.h"

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

	if (argc != 2)
		return (-1);
	scene_setup(&scene);
	mlx_setup(&scene);
	if (OK != reader(&scene, *(argv + 1)))
	{
		scene_clean(&scene);
		return (-1);
	}
	mlx_setup_init(&scene);
	printf("\n~mlx_loop running~\n");
	mlx_hook(scene.mlx->win[SCENE], 17, 0, clean_exit, &scene);
	mlx_hook(scene.mlx->win[SCENE], 2, 0, hook_key_pressed, &scene);
	mlx_loop_hook(scene.mlx->mlx, on_loop, &scene);
	mlx_loop(scene.mlx->mlx);
	scene_clean(&scene);
	return (0);
}
