/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:28:56 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/20 16:05:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	hook_key_pressed(int keycode, void *param)
{
	t_scene	*s;

	s = (t_scene *)param;
	player_move(keycode, s);
	player_rotate(keycode, s);
	minimap_show(keycode, s);
	esc_exit(keycode, s);
	return (0);
}
