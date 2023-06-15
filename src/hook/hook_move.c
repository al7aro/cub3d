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

int	player_move(int keycode, t_scene *s)
{
	if (keycode == 13)
		s->player.pos.y -= 1;
	if (keycode == 1)
		s->player.pos.y += 1;
	if (keycode == 0)
		s->player.pos.x -= 1;
	if (keycode == 2)
		s->player.pos.x += 1;
	return (0);
}

int	player_rotate(int keycode, t_scene *s)
{
	double speed;

	speed = 7 * (M_PI / 180);
	if (keycode == 123)
		s->player.dir.x = angle_fov(s->player.dir.x + (-1 * speed));
	if (keycode == 124)
		s->player.dir.x = angle_fov(s->player.dir.x + (1 * speed));
	return (0);
}
