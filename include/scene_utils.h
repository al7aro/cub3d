/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:16:16 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 13:03:03 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_UTILS_H
# define SCENE_UTILS_H

# include "cub3d.h"

void		scene_log_map(t_scene *s);
void		scene_clean(t_scene *s);
void		scene_setup(t_scene *s);
void		mlx_setup(t_scene *s);
void		mlx_setup_init(t_scene *s);

#endif
