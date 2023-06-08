/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:06 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/06 22:57:58 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	*error_new(t_map_error type, char *const line)
{
	t_error	*err;

	err = (t_error *)malloc(sizeof(t_error));
	err->type = type;
	err->line = ft_strdup(line);
	return ((void *)err);
}

void	error_delete(void *content)
{
	t_error	*err;

	err = (t_error *)content;
	free(err->line);
	free(err);
}

void	error_log(void *content)
{
	t_error	*err;

	err = (t_error *)content;
	if (err->type != OK)
	{
		printf(STR_RED"ERROR: "STR_RESET);
		if (OUT_OF_RANGE == err->type)
			printf("["STR_PURPLE"OUT_OF_RANGE"STR_RESET"]\n");
		else if (UNKNOWN_OBJECT == err->type)
			printf("["STR_PURPLE"UNKNOWN_OBJECT"STR_RESET"]\n");
		else if (BAD_SYNTAX == err->type)
			printf("["STR_PURPLE"BAD_SYNTAX"STR_RESET"]\n");
		else if (TOO_MANY_OBJ == err->type)
			printf("["STR_PURPLE"TOO_MANY_OBJ"STR_RESET"]\n");
		else if (MAP_NOT_CLOSED == err->type)
			printf("["STR_PURPLE"MAP_NOT_CLOSED"STR_RESET"]\n");
		printf("\tAt Line:\n\t\t|%s", err->line);
	}
}
