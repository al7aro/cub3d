/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:33:54 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/06 23:52:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	player_move(int keycode, t_scene *scene)
{
	if (keycode == W)
		scene->player.pos.y -= PLAYER_SPEED;
	else if (keycode == S)
		scene->player.pos.y += PLAYER_SPEED;
	else if (keycode == A)
		scene->player.pos.x -= PLAYER_SPEED;
	else if (keycode == D)
		scene->player.pos.x += PLAYER_SPEED;
	return (0);
}

int	player_rotate(int keycode, t_scene *scene)
{
	if (keycode == UP || keycode == W)
		scene->player.pos.y -= PLAYER_SPEED;
	else if (keycode == DOWN || keycode == S)
		scene->player.pos.y += PLAYER_SPEED;
	else if (keycode == LEFT || keycode == A)
		scene->player.pos.x -= PLAYER_SPEED;
	else if (keycode == RIGHT || keycode == D)
		scene->player.pos.x += PLAYER_SPEED;
	return (0);
}
