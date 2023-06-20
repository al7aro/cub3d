/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:43 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/13 15:53:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		r;
	t_list	*aux;

	r = 0;
	aux = lst;
	while (aux != NULL)
	{
		r++;
		aux = aux->next;
	}
	return (r);
}
