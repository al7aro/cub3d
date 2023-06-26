/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:36:06 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/14 16:36:07 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	look_max(int sig, unsigned long long int num)
{
	if (num > 9223372036854775806)
	{
		if (sig > 0)
			return (-1);
		else
			return (-0);
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sig;
	unsigned long long int	num;

	num = 0;
	i = 0;
	sig = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = (sig * -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = look_max(sig, num);
	return (sig * num);
}
