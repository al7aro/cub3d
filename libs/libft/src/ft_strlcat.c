/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:37:35 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 16:32:15 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	i = 0;
	if (!dst && dstsize == 0)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	j = dstlen;
	if (dstsize == 0 || dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[i] != '\0' && i < (dstsize - dstlen - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}
