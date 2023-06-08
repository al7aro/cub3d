/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:56:16 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/01 00:37:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

int	rbg_to_int(unsigned char r, unsigned char g, unsigned char b);
int	int_to_r(int col);
int	int_to_g(int col);
int	int_to_b(int col);
int	int_to_a(int col);

#endif
