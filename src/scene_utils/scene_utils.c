/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:53:16 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 12:27:29 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

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
	scene->map_size = (t_vec2){.x = 1, .y = 1};
	scene->player.dir = (t_vec2){.x = 0.0, .y = 0.0};
	scene->col[CIELLING] = 0;
	scene->col[FLOOR] = 0;
}

void	mlx_setup(t_scene *scene)
{
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->mlx->mlx = mlx_init();
}

void	mlx_setup_init(t_scene *scene)
{
	scene->mlx->img[SCENE].res = (t_vec2){.x = SCENE_WIDTH, .y = SCENE_HEIGHT};
	scene->mlx->win[SCENE] = mlx_new_window(scene->mlx->mlx,
			scene->mlx->img[SCENE].res.x, scene->mlx->img[SCENE].res.y, "cub3d");
	scene->mlx->img[SCENE].img = mlx_new_image(scene->mlx->mlx,
			scene->mlx->img[SCENE].res.x, scene->mlx->img[SCENE].res.y);
	scene->mlx->img[SCENE].addr = mlx_get_data_addr(scene->mlx->img[SCENE].img,
			&scene->mlx->img[SCENE].bpp,
			&scene->mlx->img[SCENE].line_size,
			&scene->mlx->img[SCENE].endian);

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
	if (scene->mlx->img[SCENE].img)
		mlx_destroy_image(scene->mlx->mlx, scene->mlx->img[SCENE].img);
	while (--scene->map_size.y >= 0)
		if (scene->map[(int)scene->map_size.y])
			free(scene->map[(int)scene->map_size.y]);
	if (scene->map)
		free(scene->map);
	if (scene->mlx)
	{
		if (scene->mlx->win[SCENE])
			mlx_destroy_window(scene->mlx->mlx, scene->mlx->win[SCENE]);
		if (scene->mlx->mlx)
			free(scene->mlx->mlx);
		free(scene->mlx);
	}
}
