/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:43 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/13 15:53:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*aux2;

	if (del != NULL && lst != NULL)
	{
		aux = (*lst);
		if (aux != NULL)
		{
			aux2 = aux;
			while (aux2 != NULL && aux2->next != NULL)
			{
				aux = aux2;
				del(aux2->content);
				aux2 = aux2->next;
				aux->next = NULL;
				free(aux);
			}
			aux = aux2;
			del(aux2->content);
			aux2 = aux2->next;
			aux->next = NULL;
			free(aux);
		}
		*lst = NULL;
	}
}
