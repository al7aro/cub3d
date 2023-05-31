/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   reader_map.h                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2023/04/23 01:04:37 by alopez-g          #+#    #+#            */
/*   Updated: 2023/04/23 01:04:50 by alopez-g         ###   ########.fr      */
/*                                                                           */
/* ************************************************************************** */

#ifndef READER_MAP_H
# define READER_MAP_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "cub3d.h"
# include "error_list.h"
# include "color.h"
# include <mlx.h>
# include "scene_utils.h"

t_map_error	reader(t_scene *scene, char *const path);
void		reader_texture(t_scene *scene, char *const line,
				t_error_list *err, size_t type);
void		reader_room_color(t_scene *scene, char *const line,
				t_error_list *err, size_t type);
void		reader_map(t_scene *scene, char *const line, t_error_list *err);

int			skip_space(char *const line);
int			skip_to_space(char *const line);
int			skip_num(char *const line);
char		is_space(char c);

int			check_int(char *const line, size_t *i);
int			check_color(char *const line, size_t *i);
int			read_color(char *const line);

#endif
