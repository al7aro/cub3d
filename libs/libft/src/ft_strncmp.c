/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:32:56 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/23 00:02:08 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	if (!str1 || !str2)
		return (1);
	i = 0;
	while (str1 && str2 && (str1[i] == str2[i] && str1[i] != '\0' ) && n)
	{
		n--;
		i++;
	}
	if (n == 0 || (str1[i] == 0 && str2[i] == 0))
		return (0);
	else
		return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
}
