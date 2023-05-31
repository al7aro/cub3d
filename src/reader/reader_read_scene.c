/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_read_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:12 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 23:37:04 by alopez-g         ###   ########.fr       */
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

void	reader_texture(t_scene *scene, char *const line,
	t_error_list *err, size_t type)
{
	size_t	start;
	size_t	end;
	char	*tex_path;

	start = skip_space(line);
	end = skip_to_space(line + start);
	tex_path = ft_substr(line + start, 0, end);
	tex_log(type, tex_path);
	scene->tex[type].img = mlx_xpm_file_to_image(scene->mlx, tex_path,
			&scene->tex[type].w, &scene->tex[type].h);
	if (tex_path)
		free(tex_path);
	if (scene->tex[type].img)
		scene->tex[type].addr = mlx_get_data_addr(scene->tex[type].img,
				&scene->tex[type].bpp, &scene->tex[type].len,
				&scene->tex[type].endian);
	else
		return (error_list_add(err, error_new(BAD_TEXTURE, line)));
}

void	reader_room_color(t_scene *scene, char *const line,
	t_error_list *err, size_t type)
{
	size_t	i;

	i = 0;
	if (!ft_strncmp(line + skip_space(line), "C", 1))
		type = CIELLING;
	if (!ft_strncmp(line + skip_space(line), "F", 1))
		type = FLOOR;
	scene->col[type] = read_color(line + i);
	if (scene->col[type] == -1 || check_color(line, &i) == -1)
		return (error_list_add(err, error_new(BAD_SYNTAX, line)));
	i += skip_space(line + i);
	if (*(line + i) != '\0' && *(line + i) != '#')
		return (error_list_add(err, error_new(BAD_SYNTAX, line)));
	printf("Read ");
	if (type == CIELLING)
		printf("cielling");
	else if (type == FLOOR)
		printf("floor");
	printf(" color (integer notation): %u\n", scene->col[type]);
}
