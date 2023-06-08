/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:29:08 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 13:02:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "cub3d.h"
# include "keycodes.h"
# include "stdlib.h"
# include "scene_utils.h"

int	hook_key_pressed(int keycode, void *param);
int	player_move(int keycode, t_scene *s);
int	esc_exit(int keycode, t_scene *s);

#endif
