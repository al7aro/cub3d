/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 00:02:00 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 21:48:29 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_UTILS_H
# define SCENE_UTILS_H

# include "cub3d.h"
# include "libft.h"
# include "macro.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

void	scene_log_map(t_scene *scene);
void	scene_clean(t_scene *scene);
void	scene_setup(t_scene *scene);

#endif
