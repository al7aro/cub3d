/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   reader.h                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2023/04/23 01:04:37 by alopez-g          #+#    #+#            */
/*   Updated: 2023/04/23 01:04:50 by alopez-g         ###   ########.fr      */
/*                                                                           */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "cub3d.h"
# include "color.h"
# include "macro.h"
# include "scene_utils.h"
# include <mlx.h>

/* Error Handling */
typedef enum e_map_error
{
	OK = 0,
	KO = 1,
	UNKNOWN_OBJECT,
	OUT_OF_RANGE,
	BAD_SYNTAX,
	BAD_TEXTURE,
	BAD_MAP,
	BAD_PLAYER
}				t_map_error;

typedef struct s_error
{
	t_map_error	type;
}					t_error;

typedef struct s_error_list
{
	t_list	*err;
}				t_error_list;

void		error_delete(void *content);
void		error_log(void *content);
void		*error_new(t_map_error type);

void		error_list_init(t_error_list *err_list);
void		error_list_log(t_error_list *err_list);
void		error_list_delete(t_error_list *err_list);
void		error_list_add(t_error_list *err_list, t_error *err);

/* Reader */
t_map_error	reader(t_scene *s, char *const path);
void		reader_texture(t_scene *s, char *const line,
				t_error_list *err, size_t type);
void		reader_room_color(t_scene *s, char *const line,
				t_error_list *err, size_t type);
void		reader_map(t_scene *s, char *const line, t_error_list *err);
void		reader_is_map_closed(t_scene *s, t_error_list *err);

int			skip_space(char *const line);
int			skip_to_space(char *const line);
int			skip_num(char *const line);
char		is_space(char c);

int			check_int(char *const line, size_t *i);
int			check_color(char *const line, size_t *i);
int			read_color(char *const line);

#endif
