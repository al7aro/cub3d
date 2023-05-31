/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:02:17 by alfgarci          #+#    #+#             */
/*   Updated: 2022/09/21 15:42:58 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = 0;
	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			p = (char *)&s[i];
	if (s[i] == (unsigned char)c)
		p = (char *)&s[i];
	return (p);
}
