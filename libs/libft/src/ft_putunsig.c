/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:07:58 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 18:02:52 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	get_numdigs(unsigned long int n)
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

static char	*ft_itoa_unsigned(unsigned long int n)
{
	int		i;
	int		num_digs;
	char	*cad;

	i = -1;
	num_digs = get_numdigs(n);
	cad = (char *)malloc((num_digs + 1) * sizeof(char));
	if (!cad)
		return (NULL);
	while (++i < num_digs)
	{
		cad[num_digs - i -1] = (n % 10) + 48;
		n /= 10;
	}
	cad[i] = '\0';
	return (cad);
}

int	ft_putunsig(unsigned long int n)
{
	char	*str;
	int		num_char;

	str = ft_itoa_unsigned(n);
	num_char = ft_putstr(str);
	free(str);
	return (num_char);
}
