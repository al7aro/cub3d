/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:38:43 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 00:51:09 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	shade_rays(t_scene *scene, int x, int y)
{
	(void)scene;
	(void)x;
	(void)y;
	return (rbg_to_int(0, 255, 0));
}
