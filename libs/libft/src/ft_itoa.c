/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:03:13 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 16:28:50 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	get_numdigs(unsigned int n)
{
	size_t	num;

	num = 0;
	while (n > 9)
	{
		num++;
		n /= 10;
	}
	num++;
	return (num);
}

char	*ft_itoa(int n)
{
	int		i;
	int		is_neg;
	int		num_digs;
	char	*cad;

	i = -1;
	is_neg = (n >= 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_digs = get_numdigs(n * -(n < 0) + n * (n >= 0)) + (n < 0);
	cad = (char *)malloc((num_digs + 1) * sizeof(char));
	if (!cad)
		return (NULL);
	if (n < 0)
	{
		cad[++i] = '-';
		n *= -1;
	}
	while (++i < num_digs)
	{
		cad[num_digs - i - is_neg] = (n % 10) + 48;
		n /= 10;
	}
	cad[i] = '\0';
	return (cad);
}
