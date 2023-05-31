/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:04:34 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/21 20:55:49 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				i;
	int				sing;
	unsigned int	n;

	i = 0;
	n = 0;
	sing = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sing = -1;
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - 48);
	if (n > 2147483647 && sing == 1)
		return (-1);
	else if (n > 2147483648 && sing == -1)
		return (0);
	return (n * sing);
}
