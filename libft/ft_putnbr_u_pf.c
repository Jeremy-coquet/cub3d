/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:06:05 by gudoyle           #+#    #+#             */
/*   Updated: 2024/03/08 08:36:54 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u_pf(unsigned int n, size_t *count)
{
	unsigned long	nbl;

	nbl = n;
	if (nbl >= 10)
	{
		ft_putnbr_u_pf((nbl / 10), count);
		ft_putnbr_u_pf((nbl % 10), count);
	}
	else
		ft_putchar_pf((nbl + '0'), count);
}
