/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:42:37 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/19 11:09:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	draw_point(t_img *img, t_vec2 pos, int c)
{
	int	first_char;

	if (pos.x < 0 || pos.y < 0 || pos.x >= img->res.x || pos.y >= img->res.y)
		return (0);
	first_char = pos.x * (img->bpp / 8) + pos.y * img->len;
	*(img->addr + first_char + 0) = (char)((c & 0x000000FF) >> 0);
	*(img->addr + first_char + 1) = (char)((c & 0x0000FF00) >> 8);
	*(img->addr + first_char + 2) = (char)((c & 0x00FF0000) >> 16);
	*(img->addr + first_char + 3) = (char)((c & 0xFF000000) >> 24);
	return (0);
}

int	draw_point_novector(t_img *img,	int x, int y, int c)
{
	int	first_char;

	if (x < 0 || y < 0 || x >= img->res.x || y >= img->res.y)
		return (0);
	first_char = x * (img->bpp / 8) + y * img->len;
	*(img->addr + first_char + 0) = (char)((c & 0x000000FF) >> 0);
	*(img->addr + first_char + 1) = (char)((c & 0x0000FF00) >> 8);
	*(img->addr + first_char + 2) = (char)((c & 0x00FF0000) >> 16);
	*(img->addr + first_char + 3) = (char)((c & 0xFF000000) >> 24);
	return (0);
}
