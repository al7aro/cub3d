/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:12 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/23 00:09:09 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

static char	is_tex_name_valid(char *path)
{
	char	ret;

	ret = 1;
	if (ft_strncmp(ft_strrchr(path, '.'), ".xpm", 5))
		ret = 0;
	if (path)
		free(path);
	return (ret);
}

void	reader_texture(t_scene *s, char *const line,
	t_error_list *err, size_t type)
{
	size_t	start;
	size_t	end;
	char	*tex_path;

	if (s->tex[type].img || !is_space(*line) || !*(line + skip_space(line)))
		return (error_list_add(err, error_new(BAD_TEXTURE)));
	start = skip_space(line);
	end = skip_to_space(line + start);
	tex_path = ft_substr(line + start, 0, end);
	s->tex[type].img = mlx_xpm_file_to_image(s->mlx->mlx, tex_path,
			&s->tex[type].w, &s->tex[type].h);
	end += skip_space(line + end + 1) + 1;
	s->tex[type].anim_size = ((double)ft_atoi(line + end));
	if (s->tex[type].anim_size == 0)
		s->tex[type].anim_size = 1;
	end += skip_num(line + end);
	end += skip_space(line + end);
	if (!is_tex_name_valid(tex_path)
		|| (*(line + end) != '\0'
			&& *(line + end) != '\n') || s->tex[type].anim_size <= 0
		|| s->tex[type].anim_size >= s->tex[type].w || !s->tex[type].img)
		return (error_list_add(err, error_new(BAD_TEXTURE)));
	s->tex[type].w = s->tex[type].w / s->tex[type].anim_size;
	s->tex[type].addr = mlx_get_data_addr(s->tex[type].img,
			&s->tex[type].bpp, &s->tex[type].len, &s->tex[type].endian);
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
		return (error_list_add(err, error_new(BAD_SYNTAX)));
	i += skip_space(line + i);
	if (*(line + i) != '\0' && *(line + i) != '\n')
		return (error_list_add(err, error_new(BAD_SYNTAX)));
}
