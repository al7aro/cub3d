/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_map_closed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:42:48 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/20 12:43:05 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"
/*
 * space char -> 32
*/
void	reader_is_map_closed(t_scene *scene, t_error_list *err)
{
	char	**m;
	size_t	i;
	size_t	j;
	int		position;
	char	player;

	player = 0;
	m = scene->map;
	j = 1;
	if (scene->map_size.x == 1 || scene->map_size.y == 1)
		return (error_list_add(err, error_new(BAD_MAP)));
	while (j < scene->map_size.y - 1 && *(m + j))
	{
		i = 1;
		while (i < scene->map_size.x - 1 && *(*(m + j) + i))
		{
			position = *(*(m + j) + i);
			if (*(*(m + j) + i) == '0'
				&& (*(*(m + j) + i + 1) == 32 || *(*(m + j) + i - 1) == 32
					|| *(*(m + j + 1) + i) == 32 || *(*(m + j - 1) + i) == 32))
				return (error_list_add(err, error_new(BAD_MAP)));
			if (position == 'N' || position == 'S' || position == 'E'
				|| position == 'W')
			{
				player = 1;
				scene->player.pos.x = (double)((i - 0.5) * TILE_SIZE);
				scene->player.pos.y = (double)((j - 0.5) * TILE_SIZE);
				if (position == 'N')
					scene->player.dir.x = 3 * M_PI_2;
				else if (position == 'S')
					scene->player.dir.x = M_PI_2;
				else if (position == 'E')
					scene->player.dir.x = 0;
				else if (position == 'W')
					scene->player.dir.x = M_PI;
			}
			i++;
		}
		j++;
	}
	if (!player)
		return (error_list_add(err, error_new(NO_PLAYER)));
}
