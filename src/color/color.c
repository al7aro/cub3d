/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:56:24 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 00:37:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	rbg_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	int_to_a(int col)
{
	return ((col >> 24) & 0xFF);
}

int	int_to_r(int col)
{
	return ((col >> 16) & 0xFF);
}

int	int_to_g(int col)
{
	return ((col >> 8) & 0xFF);
}

int	int_to_b(int col)
{
	return (col & 0xFF);
}
