/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 00:16:16 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/04 00:17:33 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_UTILS_H
# define SCENE_UTILS_H

# include "cub3d.h"

void		scene_log_map(t_scene *scene);
void		scene_clean(t_scene *scene);
void		scene_setup(t_scene *scene);
void		mlx_setup(t_scene *scene);

#endif
