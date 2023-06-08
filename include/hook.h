/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:29:08 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/06 23:47:03 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "cub3d.h"
# include "keycodes.h"
# include "minimap.h"

int	hook_key_pressed(int keycode, void *param);
int	player_move(int keycode, t_scene *scene);

#endif
