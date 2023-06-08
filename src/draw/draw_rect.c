/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:52:56 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/05 15:29:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	draw_rect(t_img *img, t_rect r, int c)
{
	int	x;
	int	y;

	y = r.y - 1;
	while (++y < r.y + r.h)
	{
		x = r.x - 1;
		while (++x < r.x + r.w)
			draw_point(img, (t_vec2){.x = x, .y = y}, c);
	}
	return (0);
}

int	draw_rect_border(t_img *img, t_rect r, int weight, int c)
{
	t_line	l0;
	t_line	l1;
	t_line	l2;
	t_line	l3;

	l0 = (t_line){r.x, r.y, r.x + r.w, r.y};
	l1 = (t_line){r.x, r.y, r.x, r.y + r.h};
	l2 = (t_line){r.x, r.y + r.h, r.x + r.w, r.y + r.h};
	l3 = (t_line){r.x + r.w, r.y, r.x + r.w, r.y + r.h};
	draw_line(img, l0, weight, c);
	draw_line(img, l1, weight, c);
	draw_line(img, l2, weight, c);
	draw_line(img, l3, weight, c);
	return (0);
}
