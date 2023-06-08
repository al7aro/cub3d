/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:28:56 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/06 23:42:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	hook_key_pressed(int keycode, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	player_move(keycode, scene);
	return (0);
}
