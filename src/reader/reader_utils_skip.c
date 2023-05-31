/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils_skip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:44:28 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 20:14:37 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_map.h"

int	skip_space(char *const line)
{
	int	i;

	i = 0;
	while (*(line + i) == ' ' || *(line + i) == '\t'
		|| *(line + i) == '\v' || *(line + i) == '\f'
		|| *(line + i) == '\r' || *(line + i) == '\n')
		i++;
	return (i);
}

int	skip_to_space(char *const line)
{
	int	i;

	i = 0;
	while (*(line + i) != ' ' && *(line + i) != '\t'
		&& *(line + i) != '\v' && *(line + i) != '\f'
		&& *(line + i) != '\r' && *(line + i) != '\n')
		i++;
	return (i);
}

char	is_space(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == '\n')
		return (1);
	return (0);
}

int	skip_num(char *const line)
{
	int	i;

	i = 0;
	while (*(line + i) >= '0' && *(line + i) <= '9')
		i++;
	return (i);
}
