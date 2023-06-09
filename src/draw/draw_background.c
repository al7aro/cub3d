/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:21:06 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/09 13:17:29 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	draw_background(t_img *img, int c)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < img->res.y)
	{
		x = 0;
		while (++x < img->res.x)
			draw_point(img, (t_ivec2){.x = x, .y = y}, c);
	}
	return (0);
}
