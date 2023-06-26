/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:23:44 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/23 00:42:12 by alopez-g         ###   ########.fr       */
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

void	l(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		return (-1);
	scene_setup(&scene);
	mlx_setup(&scene);
	if (OK != reader(&scene, *(argv + 1)))
		clean_exit(&scene);
	mlx_setup_init(&scene);
	mlx_hook(scene.mlx->win, 17, 0, clean_exit, &scene);
	mlx_hook(scene.mlx->win, 2, 1, hook_key_pressed, &scene);
	scene.ray = NULL;
	mlx_loop_hook(scene.mlx->mlx, on_loop, &scene);
	mlx_loop(scene.mlx->mlx);
	scene_clean(&scene);
	return (0);
}
