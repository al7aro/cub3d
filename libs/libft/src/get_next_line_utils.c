/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:33:48 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/20 14:23:24 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	int		i;
	int		len_s2;

	i = 0;
	sub = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s2 = ft_strlen((char *)s2);
	sub = ft_calloc(sizeof(char), (ft_strlen((char *)s1) + len_s2 + 1));
	if (sub == NULL)
		return (NULL);
	while (*s1)
	{
		sub[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		sub[i++] = *s2;
		s2++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	while (c > 127)
		c = c - 128;
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}
