/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:12:10 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 16:32:49 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	is_in_set(const char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

static int	len_start(const char *s1, const char *set)
{
	int	len_s;

	len_s = -1;
	while (s1[++len_s])
		if (!is_in_set(set, s1[len_s]))
			break ;
	return (len_s);
}

static int	len_finsh(const char *s1, const char *set)
{
	int	i;
	int	len_f;

	i = ft_strlen(s1);
	len_f = 0;
	while (i > 0)
	{
		if (!is_in_set(set, s1[--i]))
			break ;
		len_f++;
	}
	return (len_f);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new;
	int		len_f;
	int		len_s;
	int		i;

	if (!s1 || !set)
		return (0);
	len_s = len_start(s1, set);
	len_f = len_finsh(s1, set);
	if ((len_s + len_f) >= (int)ft_strlen(s1))
		return (ft_calloc(sizeof(char), 1));
	new = (char *)malloc((ft_strlen(s1) - len_s - len_f + 1) * sizeof(char));
	if (!new)
		return (0);
	i = -1;
	while (++i <= ((int)ft_strlen(s1) - len_s - len_f - 1))
		new[i] = s1[len_s + i];
	new[i] = '\0';
	return (new);
}
