/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:53:16 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 22:32:47 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_utils.h"

void	scene_log_map(t_scene *scene)
{
	int	i;
	int	j;

	i = -1;
	while (++i < scene->map_size.x + 2)
		printf("-");
	i = -1;
	printf("\n");
	while (++i < scene->map_size.y)
	{
		j = -1;
		printf("|");
		while (++j < scene->map_size.x)
		{
			if (scene->map[i][j] == '0')
				printf(STR_RESET"%c"STR_RESET, scene->map[i][j]);
			else if (scene->map[i][j] == '1')
				printf(STR_RED"%c"STR_RESET, scene->map[i][j]);
			else
				printf(STR_PURPLE"%c"STR_RESET, scene->map[i][j]);
		}
		printf("|\n");
	}
	while (--j >= -2)
		printf("-");
}

void	scene_setup(t_scene *scene)
{
	scene->tex[NORTH].img = (void *)0;
	scene->tex[NORTH].addr = (void *)0;
	scene->tex[SOUTH].img = (void *)0;
	scene->tex[SOUTH].addr = (void *)0;
	scene->tex[WEST].img = (void *)0;
	scene->tex[WEST].addr = (void *)0;
	scene->tex[EAST].img = (void *)0;
	scene->tex[EAST].addr = (void *)0;
	scene->map = (char **)malloc(sizeof(char *));
	scene->map[0] = ft_strdup(" ");
	scene->col[CIELLING] = 0;
	scene->col[FLOOR] = 0;
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->player.dir = (t_vec2){.x = 0.0, .y = 0.0};
	scene->map_size = (t_vec2){.x = 1, .y = 1};
}

void	scene_clean(t_scene *scene)
{
	if (scene->tex[NORTH].img)
		mlx_destroy_image(scene->mlx->mlx, scene->tex[NORTH].img);
	if (scene->tex[SOUTH].img)
		mlx_destroy_image(scene->mlx->mlx, scene->tex[SOUTH].img);
	if (scene->tex[WEST].img)
		mlx_destroy_image(scene->mlx->mlx, scene->tex[WEST].img);
	if (scene->tex[EAST].img)
		mlx_destroy_image(scene->mlx->mlx, scene->tex[EAST].img);
	while (--scene->map_size.y >= 0)
		if (scene->map[(int)scene->map_size.y])
			free(scene->map[(int)scene->map_size.y]);
	if (scene->map)
		free(scene->map);
	if (scene->mlx)
	{
		if (scene->mlx->win[RAYS])
			mlx_destroy_window(scene->mlx->mlx, scene->mlx->win[RAYS]);
		if (scene->mlx->win[SCENE])
			mlx_destroy_window(scene->mlx->mlx, scene->mlx->win[SCENE]);
		if (scene->mlx->mlx)
			free(scene->mlx->mlx);
		free(scene->mlx);
	}
}
