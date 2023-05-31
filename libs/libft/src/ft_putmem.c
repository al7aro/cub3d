/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:05:42 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/25 17:39:25 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putmem(void *p)
{
	unsigned long int	mem;

	mem = (unsigned long int)p;
	ft_putstr("0x");
	return (2 + ft_puthex(mem, 'x'));
}
