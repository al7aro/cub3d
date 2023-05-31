/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:02:05 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 21:16:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_LIST_H
# define ERROR_LIST_H

# include "libft.h"
# include "macro.h"
# include <stdio.h>

typedef enum e_map_error
{
	OK = 0,
	KO = 1,
	UNKNOWN_OBJECT,
	OUT_OF_RANGE,
	BAD_SYNTAX,
	TOO_MANY_OBJ,
	MAP_NOT_FOUND,
	BAD_TEXTURE,
	BAD_MAP
}				t_map_error;

typedef struct s_error
{
	t_map_error	type;
	char		*line;
}					t_error;

typedef struct s_error_list
{
	t_list	*err;
}				t_error_list;

void	error_delete(void *content);
void	error_log(void *content);
void	*error_new(t_map_error type, char *const line);

void	error_list_init(t_error_list *err_list);
void	error_list_log(t_error_list *err_list);
void	error_list_delete(t_error_list *err_list);
void	error_list_add(t_error_list *err_list, t_error *err);

#endif
