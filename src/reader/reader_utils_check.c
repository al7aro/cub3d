/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:44:28 by alopez-g          #+#    #+#             */
/*   Updated: 2023/05/31 22:27:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader_map.h"

int	check_int(char *const line, size_t *i)
{
	if (ft_atoi(line + *i) < 0 || ft_atoi(line + *i) > 255)
		return (-1);
	*i += skip_space(line + *i);
	*i += (*(line + *i) == '-');
	if (!skip_num(line + *i))
		return (-1);
	*i += skip_num(line + *i);
	if (*(line + *i) == ' ')
		*i += skip_space(line + *i);
	return (0);
}

int	check_color(char *const line, size_t *i)
{
	if (check_int(line, i) == -1)
		return (-1);
	*i += skip_space(line + *i);
	if (*(line + *i) != ',')
		return (-1);
	*i += 1;
	if (check_int(line, i) == -1)
		return (-1);
	*i += skip_space(line + *i);
	if (*(line + *i) != ',')
		return (-1);
	*i += 1;
	if (check_int(line, i) == -1)
		return (-1);
	return (0);
}

int	read_color(char *const line)
{
	int		r;
	int		g;
	int		b;
	size_t	i;

	i = 0;
	r = ((double)ft_atoi(line + i));
	while (*(line + i) != ',')
		i++;
	g = ((double)ft_atoi(line + ++i));
	while (*(line + i) != ',')
		i++;
	b = ((double)ft_atoi(line + ++i));
	return (rbg_to_int((unsigned char)r, (unsigned char)g, (unsigned char)b,
			(unsigned char)255));
}
