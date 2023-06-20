/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:40:21 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/17 09:40:23 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!c)
		return (0);
	while (src[i])
	{
		c[i] = src[i];
		i++;
	}
	c[i] = src[i];
	return (c);
}
