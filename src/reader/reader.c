/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:14 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/21 21:02:35 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static char	parse_colors(t_scene *s, char *const line, t_error_list *err,
	int i)
{
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
	else
		return (0);
	if (s->map_error_aux)
		error_list_add(err, error_new(BAD_MAP));
	return (1);
}

static char	*parse_line(t_scene *s, char *const line, t_error_list *err)
{
	size_t	i;

	i = skip_space(line);
	if (parse_colors(s, line, err, i))
		return (line);
	else if (is_space(*(line + i)) || *(line + i) == '1')
	{
		if (s->map_error_aux == 0)
			s->map_error_aux = 1;
		if (s->map_error_aux == 2)
			s->map_error_aux = 3;
		map_add_line(s, line);
	}
	else if (!((*(line + i) == '#') || (*(line + i) == '\0')))
		error_list_add(err, error_new(BAD_MAP));
	else if (*(line + i) == '\0' && s->map_error_aux == 1)
		s->map_error_aux = 2;
	return (line);
}

static int	check_errors(t_scene *s, t_error_list *err)
{
	char	ret;

	if (s->tex[NORTH].img == NULL || s->tex[SOUTH].img == NULL
		|| s->tex[WEST].img == NULL || s->tex[EAST].img == NULL)
		error_list_add(err, error_new(BAD_TEXTURE));
	if (s->map_error_aux >= 3)
		error_list_add(err, error_new(BAD_MAP));
	reader_is_map_closed(s, err);
	ret = (ft_lstsize(err->err) > 1);
	error_list_log_and_delete(err);
	return (ret);
}

t_map_error	reader(t_scene *s, char *const path)
{
	int				fd;
	char			*line;
	t_error_list	err_list;

	error_list_init(&err_list);
	fd = open(path, O_RDONLY);
	if (-1 == fd || ft_strncmp(ft_strrchr(path, '.'), ".cub", 5))
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
	close(fd);
	return (check_errors(s, &err_list));
}
