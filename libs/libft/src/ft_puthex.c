/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:17:28 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 17:49:16 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_puthex(unsigned long int num, char m)
{
	int		num_char;
	char	*base;

	num_char = 0;
	if (m == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
	{
		num_char += ft_puthex(num / 16, m);
		num_char += ft_puthex(num % 16, m);
	}
	else
	{
		if (num <= 9)
			num_char += ft_putchar(num + 48);
		else
			num_char += ft_putchar(base[num]);
	}
	return (num_char);
}
