/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:37:50 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 16:32:29 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*cad;

	i = -1;
	if (!s)
		return (NULL);
	cad = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cad)
		return (NULL);
	while (s[++i])
		cad[i] = f(i, s[i]);
	cad[i] = '\0';
	return (cad);
}
