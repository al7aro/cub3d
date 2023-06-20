/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <ralopez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:51:43 by ralopez-          #+#    #+#             */
/*   Updated: 2022/09/13 15:53:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_n(int nb)
{
	int	c;

	c = 0;
	if (nb < 0)
	{
		c++;
		nb = nb * -1;
	}	
	if (nb == 0)
		c = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

void	ft_numrev(char	*tab, int size)
{
	int		i;
	int		x;
	char	aux;
	int		j;

	i = 0;
	if ((*tab) == '-')
		i = 1;
	x = (size / 2);
	if (size % 2 == 1)
		x = x + 1;
	j = 1;
	while (i < x)
	{
		aux = *(tab + i);
		*(tab + i) = *(tab + (size - j));
		*(tab + (size - j)) = aux;
		j++;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)ft_calloc(ft_strlen_n(n) + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
	{
		n = n * -1;
		str[i++] = '-';
	}	
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	str[i] = '\0';
	ft_numrev(str, ft_strlen(str));
	return (str);
}
