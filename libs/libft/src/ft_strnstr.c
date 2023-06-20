/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:35:42 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/17 09:35:50 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && len)
	{
		j = 0;
		while (little[j] == big[i + j] && (len - j > 0))
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		len--;
		i++;
	}
	return (NULL);
}
