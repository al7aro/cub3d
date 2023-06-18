/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:33:54 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 13:01:59 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "macro.h"


void	scene_log_map2(t_scene *s, int x, int y)
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
			if (i== x && j == y)
				printf(STR_PURPLE"%c"STR_RESET, 'S');
			else if (s->map[i][j] == '0')
				printf(STR_RESET"%c"STR_RESET, s->map[i][j]);
			else if (s->map[i][j] == '1')
				printf(STR_RED"%c"STR_RESET, s->map[i][j]);
			else
				printf(STR_RESET"%c"STR_RESET, '0');
			
		}
		printf("|\n");
	}
	while (--j >= -2)
		printf("-");
}

int	move_player(int key)
{
	if (key == W || key == W_LINUX || key == S || key == S_LINUX
		|| key == A || key == A_LINUX || key == D || key == D_LINUX)
		return (1);
	return (0);
}

int	player_move(int keycode, t_scene *s)
{
	double	angle;
	double	movestep;
	double	next_x;
	double	next_y;
	double move_angle;

	if (move_player(keycode) == 0)
		return (0);
	move_angle = s->player.dir.x;
	if (keycode == W || keycode == W_LINUX)
		angle = angle_fov(move_angle);
	if (keycode == S || keycode == S_LINUX)
		angle = angle_fov(move_angle+ M_PI);
	if (keycode == A || keycode == A_LINUX)
		angle = angle_fov(move_angle - M_PI_2);
	if (keycode == D || keycode == D_LINUX)
		angle = angle_fov(move_angle + M_PI_2);
	movestep = 0.35 * TILE_SIZE;
	next_x = s->player.pos.x + (cos(angle) * movestep);
	next_y = s->player.pos.y + (sin(angle) * movestep);
	if (!hits_walll(s, next_x, next_y))
	{
		s->player.pos.x = next_x;
		s->player.pos.y = next_y;
	}
	return (0);
}

int	player_rotate(int keycode, t_scene *s)
{
	double speed;

	speed = 7 * (M_PI / 180);
	if (keycode == LEFT || keycode == LEFT_LINUX)
		s->player.dir.x = angle_fov(s->player.dir.x + (-1 * speed));
	if (keycode == RIGHT || keycode == RIGHT_LINUX)
		s->player.dir.x = angle_fov(s->player.dir.x + (1 * speed));
	return (0);
}
