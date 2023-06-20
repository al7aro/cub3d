/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:37:07 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/17 09:37:08 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	while (c > 127)
		c = c - 128;
	p = NULL;
	while (*s)
	{
		if (*s == c)
			p = (char *)s;
		s++;
	}
	if (*s == c)
		p = (char *)s;
	return (p);
}
