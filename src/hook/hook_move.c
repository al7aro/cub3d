/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:33:54 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/20 23:56:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "macro.h"

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
	double	next_x;
	double	next_y;
	double	move_angle;

	if (move_player(keycode) == 0)
		return (0);
	move_angle = s->player.dir.x;
	if (keycode == W || keycode == W_LINUX)
		angle = angle_fov(move_angle);
	if (keycode == S || keycode == S_LINUX)
		angle = angle_fov(move_angle + M_PI);
	if (keycode == A || keycode == A_LINUX)
		angle = angle_fov(move_angle - M_PI_2);
	if (keycode == D || keycode == D_LINUX)
		angle = angle_fov(move_angle + M_PI_2);
	next_x = s->player.pos.x + (cos(angle) * PLAYER_SPEED * 2);
	next_y = s->player.pos.y + (sin(angle) * PLAYER_SPEED * 2);
	if (!hits_walll(s, next_x, next_y))
	{
		s->player.pos.x += (cos(angle) * PLAYER_SPEED);
		s->player.pos.y += (sin(angle) * PLAYER_SPEED);
	}
	return (0);
}

int	player_rotate(int keycode, t_scene *s)
{
	if (keycode == LEFT || keycode == LEFT_LINUX)
		s->player.dir.x = angle_fov(s->player.dir.x + (-1 * ROTATION_SPEED));
	if (keycode == RIGHT || keycode == RIGHT_LINUX)
		s->player.dir.x = angle_fov(s->player.dir.x + (1 * ROTATION_SPEED));
	return (0);
}
