/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:20:45 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 16:31:15 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**fail_free(char **arr_s, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(arr_s[i++]);
	free(arr_s);
	return (NULL);
}

static int	count_strs(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_word(const char *s, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = -1;
	len_word = 0;
	while (s[len_word] && s[len_word] != c)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (++i < len_word)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strs = (char **)malloc((count_strs(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			strs[i++] = get_word(s, c);
			if (strs[i - 1] == NULL)
				return (fail_free(strs, i - 1));
		}
		while (*s && *s != c)
			s++;
	}
	strs[i] = 0;
	return (strs);
}
