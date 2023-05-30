/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:10:38 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 17:42:52 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	flags(const char flag, va_list args)
{
	int		num_char;
	char	*aux;

	num_char = 0;
	if (flag == 'c')
		num_char += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		num_char += ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		num_char += ft_putmem(va_arg(args, void *));
	else if (flag == 'i' || flag == 'd')
	{
		aux = ft_itoa(va_arg(args, int));
		num_char += ft_putstr(aux);
		free(aux);
	}
	else if (flag == 'u')
		num_char += ft_putunsig(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		num_char += ft_puthex(va_arg(args, unsigned int), flag);
	else if (flag == '%')
		num_char += ft_putchar('%');
	return (num_char);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		num_char;
	va_list	args;

	i = -1;
	num_char = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				break ;
			num_char += flags(str[++i], args);
		}
		else
			num_char += ft_putchar(str[i]);
	}
	va_end(args);
	return (num_char);
}
