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

int	player_move(int keycode, t_scene *s)
{
	if (keycode == W || keycode == W_LINUX)
		s->player.pos.y += 2;
	if (keycode == S || keycode == S_LINUX)
		s->player.pos.y -= 2;
	if (keycode == A || keycode == A_LINUX)
		s->player.pos.x += 2;
	if (keycode == D || keycode == D_LINUX)
		s->player.pos.x -= 2;
	if (keycode == A || keycode == A_LINUX || keycode == S || keycode == S_LINUX
		|| keycode == D || keycode == D_LINUX || keycode == W || keycode == W_LINUX)
	{
		scene_log_map2(s,  (s->player.pos.y -10)/20,(s->player.pos.x -10)/20);
		//printf("\nplayer: (%f, %f) orientation: %f \n", s->player.pos.x, s->player.pos.y, s->player.dir.x);
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
	/*if (keycode == LEFT || keycode == RIGHT || keycode == LEFT_LINUX || keycode == RIGHT_LINUX)
	{
		printf("player: (%f, %f) orientation: %f \n", s->player.pos.x, s->player.pos.y, s->player.dir.x);
	}*/
	return (0);
}
