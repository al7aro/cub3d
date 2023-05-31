/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:05:48 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 16:32:10 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	char	*save;
	int		i;
	int		len1;
	int		len2;

	i = -1;
	if (!s1)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	save = tmp;
	if (!tmp)
		return (NULL);
	while (++i < len1)
		*save++ = s1[i];
	i = -1;
	while (++i < len2)
		*save++ = s2[i];
	*save = '\0';
	return (tmp);
}
