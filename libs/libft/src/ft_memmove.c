/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:57:03 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 16:30:21 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (src < dst)
	{
		j = (int)len - 1;
		while (j >= 0)
		{
				*(unsigned char *)(dst + j) = *(unsigned char *)(src + j);
				j--;
		}
		return (dst);
	}
	while (i < len)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
