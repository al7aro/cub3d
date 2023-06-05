/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_cub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:34:25 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/05 01:03:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_CUB_H
# define MATH_CUB_H

# include <math.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct s_ivec2
{
	int	x;
	int	y;
}				t_ivec2;

double	math_len(t_vec2 v1, t_vec2 v2);

#endif
