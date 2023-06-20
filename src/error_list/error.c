/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:06 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/20 13:38:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	*error_new(t_map_error type)
{
	t_error	*err;

	err = (t_error *)malloc(sizeof(t_error));
	err->type = type;
	return ((void *)err);
}

void	error_delete(void *content)
{
	t_error	*err;

	err = (t_error *)content;
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
		else if (MAP_NOT_CLOSED == err->type)
			printf("["STR_PURPLE"MAP_NOT_CLOSED"STR_RESET"]\n");
		else if (NO_PLAYER == err->type)
			printf("["STR_PURPLE"NO_PLAYER"STR_RESET"]\n");
		else if (MAP_NOT_FOUND == err->type)
			printf("["STR_PURPLE"MAP_NOT_FOUND"STR_RESET"]\n");
		else if (BAD_TEXTURE == err->type)
			printf("["STR_PURPLE"BAD_TEXTURE"STR_RESET"]\n");
		else if (TEXTURE_NOT_FOUND == err->type)
			printf("["STR_PURPLE"TEXTURE_NOT_FOUND"STR_RESET"]\n");
		else if (BAD_MAP == err->type)
			printf("["STR_PURPLE"BAD_MAP"STR_RESET"]\n");
		else if (INVALID_SUFFIX == err->type)
			printf("["STR_PURPLE"INVALID_SUFFIX"STR_RESET"]\n");
		else if (EMPTY_MAP == err->type)
			printf("["STR_PURPLE"EMPTY_MAP"STR_RESET"]\n");
		else
			printf("["STR_PURPLE"Unknown"STR_RESET"]\n");
	}
}
