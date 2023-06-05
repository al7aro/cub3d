/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:09:20 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/05 15:31:25 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	draw_circle(t_img *img, t_vec2 pos, int r, int c)
{
	int	x;
	int	y;

	y = pos.y - r - 1;
	while (++y < pos.y + r)
	{
		x = pos.x - r - 1;
		while (++x < pos.x + r)
			if (math_len((t_vec2){x, y}, (t_vec2){pos.x, pos.y}) < r)
				draw_point(img, (t_vec2){.x = x, .y = y}, c);
	}
	return (0);
}
