/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:07:48 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 17:08:26 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*read_fd(int fd, char *buffer)
{
	char	*buff_tmp;
	char	*aux;
	int		last_read;

	last_read = 1;
	buff_tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_tmp)
		return (NULL);
	while (last_read > 0)
	{
		last_read = read(fd, buff_tmp, BUFFER_SIZE);
		if (last_read == -1)
		{
			free(buff_tmp);
			return (NULL);
		}
		buff_tmp[last_read] = '\0';
		aux = ft_strjoin(buffer, buff_tmp);
		free(buffer);
		buffer = aux;
		if (ft_strchr(buff_tmp, '\n'))
			break ;
	}
	free(buff_tmp);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 2);
	return (line);
}

static char	*rest_car(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rest = (char *)malloc((ft_strlen(buffer) + 1 - i) * sizeof(char));
	if (!rest)
		return (NULL);
	while (buffer[++i])
		rest[j++] = buffer[i];
	rest[j] = '\0';
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buffer[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) || fd < 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = (char *)malloc(sizeof(char));
		buffer[fd][0] = '\0';
	}
	buffer[fd] = read_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	next_line = get_line(buffer[fd]);
	buffer[fd] = rest_car(buffer[fd]);
	return (next_line);
}
