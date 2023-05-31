/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:11:27 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 22:26:34 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_map.h"
#include "cub3d.h"

static char	is_player(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}

char	check_map_line(t_scene *scene, char *line)
{
	size_t	i;

	i = skip_space(line);
	while (*(line + i) == '1' || *(line + i) == '0' || is_player(*(line + i)))
	{
		if (is_player(*(line + i))
			&& (scene->player.dir.x != 0 || scene->player.dir.y != 0))
			return (0);
		if (*(line + i) == 'N')
			scene->player.dir = (t_vec2){.x = 0, .y = 1};
		else if (*(line + i) == 'S')
			scene->player.dir = (t_vec2){.x = 0, .y = -1};
		else if (*(line + i) == 'E')
			scene->player.dir = (t_vec2){.x = 1, .y = 0};
		else if (*(line + i) == 'W')
			scene->player.dir = (t_vec2){.x = -1, .y = 0};
		i++;
	}
	if (*(line + i - 1) != '1')
		return (0);
	return (1);
}

static char	*resize_line(char *str, size_t size)
{
	char	*new_line;
	size_t	i;
	size_t	str_size;

	i = -1;
	str_size = ft_strlen(str);
	new_line = (char *)malloc(sizeof(char) * size + 1 + 1);
	while (++i < size)
	{
		if (i >= str_size)
			new_line[i] = ' ';
		else
		{
			if (str[i] == '\n')
				new_line[i] = ' ';
			else
				new_line[i] = str[i];
		}
	}
	if (str)
		free(str);
	return (new_line);
}

void	map_add_line(t_scene *scene, char *const line)
{
	char	**new_map;
	size_t	i;

	i = -1;
	scene->map_size.y++;
	if (scene->map_size.x < ft_strlen(line))
		scene->map_size.x = ft_strlen(line) + 1;
	new_map = (char **)malloc(sizeof(char *) * scene->map_size.y);
	while (++i < scene->map_size.y - 1)
		new_map[i] = resize_line(scene->map[i], scene->map_size.x);
	new_map[i] = resize_line(ft_strjoin(" ", line), scene->map_size.x);
	if (scene->map)
		free(scene->map);
	scene->map = new_map;
}

void	reader_map(t_scene *scene, char *const line, t_error_list *err)
{
	if (!check_map_line(scene, line))
		return (error_list_add(err, error_new(BAD_MAP, line)));
	map_add_line(scene, line);
}
