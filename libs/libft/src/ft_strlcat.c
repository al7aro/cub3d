/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:41:44 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/17 09:41:45 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	len_dest = ft_strlen(dest);
	i = len_dest;
	if (len_dest >= dstsize)
		return (len_src + dstsize);
	while (src[i - len_dest] && (i + 1) < dstsize)
	{
		dest[i] = src[i - len_dest];
		i++;
	}
	if (len_dest < dstsize)
		dest[i] = '\0';
	return (len_dest + len_src);
}
