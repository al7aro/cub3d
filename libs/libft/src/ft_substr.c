/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:24:31 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/24 16:37:24 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *cad, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	sub = NULL;
	if ((int)len < 0)
		return (NULL);
	if (cad != NULL)
	{
		if (len < ft_strlen(cad))
			sub = (char *)ft_calloc(len + 1, sizeof(char));
		else
			sub = (char *)ft_calloc(ft_strlen(cad) + 1, sizeof(char));
		if (sub == NULL)
			return (NULL);
		while (len && ft_strlen((char *)cad) > start && cad[start])
		{
			sub[i] = cad[start];
			i++;
			start++;
			len--;
		}
		sub[i] = '\0';
	}
	return (sub);
}
