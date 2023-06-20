/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:43 by ralopez-          #+#    #+#             */
/*   Updated: 2023/06/20 14:19:42 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	excep_case(int n, int fd)
{
	if (n == -2147483648)
	{
		n = 147483648;
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		a[10];
	int		i;
	char	c;

	i = 0;
	if (n == -2147483648)
		n = excep_case(n, fd);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (n != 0 && n != -2147483648)
	{
		a[i] = (n % 10);
		n = (n / 10);
		i++;
	}
	while (--i >= 0 && n != -2147483648)
	{
		c = a[i] + '0';
		ft_putchar_fd(c, fd);
	}
}
