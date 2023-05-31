/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:08:34 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 00:09:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	shade_scene(t_scene *scene, int x, int y)
{
	(void)scene;
	(void)x;
	(void)y;
	return (rbg_to_int(255, 0, 88));
}
