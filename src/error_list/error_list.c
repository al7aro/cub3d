/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:24:04 by alopez-g          #+#    #+#             */
/*   Updated: 2023/04/23 00:56:59 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_list.h"

void	error_list_init(t_error_list *err_list)
{
	err_list->err = ft_lstnew(error_new(OK, "No error\n"));
}

void	error_list_add(t_error_list *err_list, t_error *err)
{
	t_list	*new;

	new = ft_lstnew(err);
	ft_lstadd_back(&(err_list->err), new);
}

void	error_list_log(t_error_list *err_list)
{
	ft_lstiter(err_list->err, error_log);
}

void	error_list_delete(t_error_list *err_list)
{
	ft_lstclear(&err_list->err, error_delete);
}
