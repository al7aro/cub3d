/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:12 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/19 13:06:33 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static void	tex_log(int index, char *tex_path)
{
	printf("Read ");
	if (index == NORTH)
		printf("north");
	if (index == SOUTH)
		printf("south");
	if (index == WEST)
		printf("west");
	if (index == EAST)
		printf("east");
	printf(" texture: [%s]\n", tex_path);
}

void	reader_texture(t_scene *s, char *const line,
	t_error_list *err, size_t type)
{
	size_t	start;
	size_t	end;
	char	*tex_path;

	start = skip_space(line);
	end = skip_to_space(line + start);
	tex_path = ft_substr(line + start, 0, end);
	tex_log(type, tex_path);
	s->tex[type].img = mlx_xpm_file_to_image(s->mlx->mlx, tex_path,
			&s->tex[type].w, &s->tex[type].h);
	if (tex_path)
		free(tex_path);
	s->tex[type].anim_size = 16;
	s->anim_current = 0;
	s->tex[type].w = s->tex[type].w / s->tex[type].anim_size;
	if (s->tex[type].img)
		s->tex[type].addr = mlx_get_data_addr(s->tex[type].img,
				&s->tex[type].bpp, &s->tex[type].len,
				&s->tex[type].endian);
	else
		return (error_list_add(err, error_new(BAD_TEXTURE, line)));
}

void	reader_room_color(t_scene *s, char *const line,
	t_error_list *err, size_t type)
{
	size_t	i;

	i = 0;
	if (!ft_strncmp(line + skip_space(line), "C", 1))
		type = CIELLING;
	if (!ft_strncmp(line + skip_space(line), "F", 1))
		type = FLOOR;
	s->col[type] = read_color(line + i);
	if (s->col[type] == -1 || check_color(line, &i) == -1)
		return (error_list_add(err, error_new(BAD_SYNTAX, line)));
	i += skip_space(line + i);
	if (*(line + i) != '\0' && *(line + i) != '#')
		return (error_list_add(err, error_new(BAD_SYNTAX, line)));
	printf("Read ");
	if (type == CIELLING)
		printf("cielling");
	else if (type == FLOOR)
		printf("floor");
	printf(" color (integer notation): %u\n", s->col[type]);
}
