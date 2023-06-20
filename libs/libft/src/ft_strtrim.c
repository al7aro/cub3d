/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:43 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/13 15:53:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_str;
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	j = ft_strlen((char *)s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strrchr(set, s1[j - 1]) && j > i)
		j--;
	len_str = j - i;
	str = ft_calloc(len_str + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (char *) &s1[i], len_str + 1);
	return (str);
}
