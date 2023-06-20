/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:33:26 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/20 14:23:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*exchange(char *text, char *cad)
{
	char	*text_aux;

	text_aux = ft_strjoin(text, cad);
	free(text);
	return (text_aux);
}

static char	*leer(int fd, char *text)
{
	int		bytes_read;
	char	*cad;

	if (text == NULL)
		text = ft_calloc(1, 1);
	cad = (char *)ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (!cad)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cad, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cad);
			return (NULL);
		}
		cad[bytes_read] = 0;
		text = exchange(text, cad);
		if (ft_strchr(text, '\n'))
			break ;
	}
	free(cad);
	return (text);
}

char	*obtain_line(char *text)
{
	char	*res;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	res = NULL;
	res = (char *)ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		res[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*clean_text(char *text)
{
	char	*aux;
	int		i;
	int		a;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	aux = NULL;
	if (text[i] == '\n')
		i++;
	aux = (char *)ft_calloc((ft_strlen(text) - i) + 1, sizeof(char));
	if (!aux)
		return (NULL);
	a = 0;
	while (text[i])
		aux[a++] = text[i++];
	free(text);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*text[1024];
	char		*line;

	line = NULL;
	if (read(fd, 0, 0) < 0)
	{
		if (text[fd] != NULL)
		{
			free(text[fd]);
			text[fd] = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	text[fd] = leer(fd, text[fd]);
	if (!text[fd])
		return (NULL);
	line = obtain_line(text[fd]);
	text[fd] = clean_text(text[fd]);
	return (line);
}
