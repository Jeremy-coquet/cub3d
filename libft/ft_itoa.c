/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:56:56 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/19 15:20:59 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	shorter(int n, long nbl, int size, char *str)
{
	int	i;

	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (size != 0)
	{
		str[i] = (nbl / size) + '0';
		nbl %= size;
		size /= 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	long	nbl;
	char	*str;
	int		i;
	int		size;

	i = 1;
	size = 1;
	nbl = n;
	if (nbl < 0)
	{
		nbl *= -1;
		i++;
	}
	while (nbl / size >= 10)
	{
		size *= 10;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	shorter(n, nbl, size, str);
	return (str);
}
