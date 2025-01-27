/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 08:24:24 by gudoyle           #+#    #+#             */
/*   Updated: 2024/03/08 08:36:51 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_pf(int n, size_t *count)
{
	long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_pf('-', count);
		nbl *= -1;
	}
	if (nbl >= 10)
	{
		ft_putnbr_pf((nbl / 10), count);
		ft_putnbr_pf((nbl % 10), count);
	}
	else
		ft_putchar_pf((nbl + '0'), count);
}
