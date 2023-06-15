/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:20:03 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/08 12:58:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	low(t_img *img, t_line l, int c)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;

	dx = l.x1 - l.x0;
	dy = l.y1 - l.y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	while (l.x0++ < l.x1)
	{
		draw_point_novector(img, l.x0, l.y0, c);
		if (d > 0)
		{
			l.y0 += yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
	}
}

static void	high(t_img *img, t_line l, int c)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;

	dx = l.x1 - l.x0;
	dy = l.y1 - l.y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	while (l.y0++ < l.y1)
	{
		
		draw_point_novector(img, l.x0, l.y0, c);
		if (d > 0)
		{
			l.x0 += xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
	}
}

int	draw_line(t_img *img, t_line l, int c)
{
	if (fabs(l.y1 - l.y0) < fabs(l.x1 - l.x0))
		low(img, l, c);
	else
		high(img, l, c);
	return (0);
}
