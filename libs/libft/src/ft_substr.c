/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:48:19 by alfgarci          #+#    #+#             */
/*   Updated: 2022/10/20 16:53:53 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (start >= ft_strlen(s))
		return (ft_calloc(sizeof(char), 1));
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)(s + start), len + 1);
	return (sub);
}
