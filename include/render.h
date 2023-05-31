/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:08:46 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 00:41:27 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "mlx.h"
# include "color.h"

int		pixel_buffer_put(t_img *img, int x, int y, int c);
void	render(t_scene *scene, int type);

int		shade_scene(t_scene *scene, int x, int y);
int		shade_rays(t_scene *scene, int x, int y);

#endif
