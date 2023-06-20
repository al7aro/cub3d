/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:39:01 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/17 09:39:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (c > 127)
		c = c - 128;
	while (*s)
	{
		if (*s == c)
		{
			p = (char *)s;
			break ;
		}
		s++;
	}
	if (*s == c)
		p = (char *)s;
	return (p);
}
