/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:14 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/21 19:47:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static char	*parse_line(t_scene *s, char *const line, t_error_list *err)
{
	size_t	i;

	i = skip_space(line);
	if (!ft_strncmp(line + i, "NO", 2))
		reader_texture(s, line + i + 2, err, NORTH);
	else if (!ft_strncmp(line + i, "SO", 2))
		reader_texture(s, line + i + 2, err, SOUTH);
	else if (!ft_strncmp(line + i, "WE", 2))
		reader_texture(s, line + i + 2, err, WEST);
	else if (!ft_strncmp(line + i, "EA", 2))
		reader_texture(s, line + i + 2, err, EAST);
	else if (!ft_strncmp(line + i, "F", 1))
		reader_room_color(s, line + i + 1, err, FLOOR);
	else if (!ft_strncmp(line + i, "C", 1))
		reader_room_color(s, line + i + 1, err, CIELLING);
	else if (is_space(*(line + i)) || *(line + i) == '1')
		map_add_line(s, line);
	else if (!((*(line + i) == '#') || (*(line + i) == '\0')))
		error_list_add(err, error_new(UNKNOWN_OBJECT));
	return (line);
}

static void	is_item_missing(t_scene *s, t_error_list *err)
{
	if (s->tex[NORTH].img == NULL || s->tex[SOUTH].img == NULL
		|| s->tex[WEST].img == NULL || s->tex[EAST].img == NULL)
		error_list_add(err, error_new(BAD_TEXTURE));
}

t_map_error	reader(t_scene *s, char *const path)
{
	int				fd;
	char			*line;
	t_error_list	err_list;

	error_list_init(&err_list);
	fd = open(path, O_RDONLY);
	if (-1 == fd || ft_strncmp(ft_strchr(path, '.'), ".cub", 5))
	{
		error_list_add(&err_list, error_new(BAD_FILE));
		if (fd != -1)
			close(fd);
		error_list_log_and_delete(&err_list);
		return (BAD_FILE);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(parse_line(s, line, &err_list));
		line = get_next_line(fd);
	}
	reader_is_map_closed(s, &err_list);
	is_item_missing(s, &err_list);
	error_list_log_and_delete(&err_list);
	close(fd);
	return ((ft_lstsize(err_list.err) > 1));
}
