/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:16:37 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/17 10:16:39 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	c;
	char	*dest2;
	char	*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	c = 0;
	if (src == NULL && dest == NULL)
		return (0);
	if (src < dest)
	{
		c = 1;
		while (c < (n + 1))
		{
			(dest2)[n - c] = (src2)[n - c];
			c++;
		}
	}
	else
	{
		while (c++ < n)
			(*dest2++) = (*src2++);
	}
	return (dest);
}
