/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_map_closed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:42:48 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/22 22:53:47 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static char	set_player_pos(t_scene *scene, int x, int y, int position)
{
	scene->player.pos.x = (double)((x + 0.5) * TILE_SIZE);
	scene->player.pos.y = (double)((y + 0.5) * TILE_SIZE);
	if (position == 'N')
		scene->player.dir.x = 3 * M_PI_2;
	else if (position == 'S')
		scene->player.dir.x = M_PI_2;
	else if (position == 'E')
		scene->player.dir.x = 0;
	else if (position == 'W')
		scene->player.dir.x = M_PI;
	return (1);
}

static char	is_player(char position)
{
	return (position == 'N' || position == 'S'
		|| position == 'E' || position == 'W');
}

static char	wall_is_open(char **m, int x, int y)
{
	char	flag;

	flag = 0;
	if ((*(*(m + y) + x) == '0'
			|| *(*(m + y) + x) == 'N'
			|| *(*(m + y) + x) == 'S'
			|| *(*(m + y) + x) == 'E'
			|| *(*(m + y) + x) == 'W')
		&& (*(*(m + y) + x + 1) == 32 || *(*(m + y) + x - 1) == 32
			|| *(*(m + y + 1) + x) == 32 || *(*(m + y - 1) + x) == 32))
		flag = 1;
	if ((*(*(m + y) + x) != '1' && *(*(m + y) + x) != '0'
			&& *(*(m + y) + x) != ' ' && !is_player(*(*(m + y) + x))))
		flag = 1;
	return (flag);
}

/*
 * space char -> 32
*/
void	reader_is_map_closed(t_scene *scene, t_error_list *err)
{
	char	**m;
	size_t	i;
	size_t	j;
	char	player;

	map_add_line(scene, " ");
	player = 0;
	m = scene->map;
	j = 0;
	if (scene->map_size.x <= 1 || scene->map_size.y <= 1
		|| scene->map_size.x >= MAP_LIMIT_X || scene->map_size.y >= MAP_LIMIT_Y)
		return (error_list_add(err, error_new(BAD_MAP)));
	while (++j < scene->map_size.y - 1 && *(m + j))
	{
		i = 0;
		while (++i < scene->map_size.x - 1 && *(*(m + j) + i))
		{
			if (wall_is_open(m, i, j))
				return (error_list_add(err, error_new(BAD_MAP)));
			if (is_player(*(*(m + j) + i)))
				player += set_player_pos(scene, i, j, *(*(m + j) + i));
		}
	}
	if (player != 1)
		return (error_list_add(err, error_new(BAD_PLAYER)));
}
