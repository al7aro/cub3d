/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:53:16 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 13:00:25 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	scene_log_map(t_scene *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->map_size.x + 2)
		printf("-");
	i = -1;
	printf("\n");
	while (++i < s->map_size.y)
	{
		j = -1;
		printf("|");
		while (++j < s->map_size.x)
		{
			if (s->map[i][j] == '0')
				printf(STR_RESET"%c"STR_RESET, s->map[i][j]);
			else if (s->map[i][j] == '1')
				printf(STR_RED"%c"STR_RESET, s->map[i][j]);
			else
				printf(STR_PURPLE"%c"STR_RESET, s->map[i][j]);
		}
		printf("|\n");
	}
	while (--j >= -2)
		printf("-");
}

void	scene_setup(t_scene *s)
{
	s->tex[NORTH].img = (void *)0;
	s->tex[NORTH].addr = (void *)0;
	s->tex[SOUTH].img = (void *)0;
	s->tex[SOUTH].addr = (void *)0;
	s->tex[WEST].img = (void *)0;
	s->tex[WEST].addr = (void *)0;
	s->tex[EAST].img = (void *)0;
	s->tex[EAST].addr = (void *)0;
	s->map = (char **)malloc(sizeof(char *));
	s->map[0] = ft_strdup(" ");
	s->map_size = (t_vec2){.x = 1, .y = 1};
	s->player.dir = (t_vec2){.x = 0.0, .y = 0.0};
	s->col[CIELLING] = 0;
	s->col[FLOOR] = 0;
}

void	mlx_setup(t_scene *scene)
{
	scene->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	scene->mlx->mlx = mlx_init();
}

void	mlx_setup_init(t_scene *s)
{
	s->mlx->img[SCENE].res = (t_vec2){.x = SCENE_WIDTH, .y = SCENE_HEIGHT};
	s->mlx->win[SCENE] = mlx_new_window(s->mlx->mlx,
			s->mlx->img[SCENE].res.x, s->mlx->img[SCENE].res.y, "cub3d");
	s->mlx->img[SCENE].img = mlx_new_image(s->mlx->mlx,
			s->mlx->img[SCENE].res.x, s->mlx->img[SCENE].res.y);
	s->mlx->img[SCENE].addr = mlx_get_data_addr(s->mlx->img[SCENE].img,
			&s->mlx->img[SCENE].bpp,
			&s->mlx->img[SCENE].line_size,
			&s->mlx->img[SCENE].endian);
}

void	scene_clean(t_scene *s)
{
	if (s->tex[NORTH].img)
		mlx_destroy_image(s->mlx->mlx, s->tex[NORTH].img);
	if (s->tex[SOUTH].img)
		mlx_destroy_image(s->mlx->mlx, s->tex[SOUTH].img);
	if (s->tex[WEST].img)
		mlx_destroy_image(s->mlx->mlx, s->tex[WEST].img);
	if (s->tex[EAST].img)
		mlx_destroy_image(s->mlx->mlx, s->tex[EAST].img);
	if (s->mlx->img[SCENE].img)
		mlx_destroy_image(s->mlx->mlx, s->mlx->img[SCENE].img);
	while (--s->map_size.y >= 0)
		if (s->map[(int)s->map_size.y])
			free(s->map[(int)s->map_size.y]);
	if (s->map)
		free(s->map);
	if (s->mlx)
	{
		if (s->mlx->win[SCENE])
			mlx_destroy_window(s->mlx->mlx, s->mlx->win[SCENE]);
		if (s->mlx->mlx)
			free(s->mlx->mlx);
		free(s->mlx);
	}
}
