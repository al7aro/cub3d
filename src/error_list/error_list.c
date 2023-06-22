/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:04 by alopez-g          #+#    #+#             */
/*   Updated: 2023/06/22 22:45:11 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

void	error_list_init(t_error_list *err_list)
{
	err_list->err = ft_lstnew(error_new(OK));
}

void	error_list_add(t_error_list *err_list, t_error *err)
{
	t_list	*new;

	new = ft_lstnew(err);
	ft_lstadd_back(&(err_list->err), new);
}

void	error_list_log(t_error_list *err_list)
{
	t_error	*err;

	err = (t_error *)(err_list->err->content);
	if (err_list->err->next)
		err = (t_error *)(err_list->err->next->content);
	if (err->type != OK)
	{
		printf(STR_RED"ERROR: "STR_RESET);
		if (OUT_OF_RANGE == err->type)
			printf("["STR_PURPLE"OUT_OF_RANGE"STR_RESET"]\n");
		else if (UNKNOWN_OBJECT == err->type)
			printf("["STR_PURPLE"UNKNOWN_OBJECT"STR_RESET"]\n");
		else if (BAD_SYNTAX == err->type)
			printf("["STR_PURPLE"BAD_SYNTAX"STR_RESET"]\n");
		else if (BAD_PLAYER == err->type)
			printf("["STR_PURPLE"BAD_PLAYER"STR_RESET"]\n");
		else if (BAD_TEXTURE == err->type)
			printf("["STR_PURPLE"BAD_TEXTURE"STR_RESET"]\n");
		else if (BAD_MAP == err->type)
			printf("["STR_PURPLE"BAD_MAP"STR_RESET"]\n");
		else if (BAD_FILE == err->type)
			printf("["STR_PURPLE"BAD_FILE"STR_RESET"]\n");
		else
			printf("["STR_PURPLE"Unknown"STR_RESET"]\n");
	}
}

void	error_list_delete(t_error_list *err_list)
{
	ft_lstclear(&err_list->err, error_delete);
}

void	error_list_log_and_delete(t_error_list *err_list)
{
	error_list_log(err_list);
	error_list_delete(err_list);
}
