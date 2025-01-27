/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:28:27 by gudoyle           #+#    #+#             */
/*   Updated: 2024/11/13 12:43:41 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_pf(char *base, unsigned long long n, size_t *count)
{
	unsigned long	nbl;

	nbl = n;
	if (nbl >= ft_strlen(base))
	{
		ft_putnbr_base_pf(base, (nbl / (ft_strlen(base))), count);
		ft_putnbr_base_pf(base, (nbl % (ft_strlen(base))), count);
	}
	else
		ft_putchar_pf((base[nbl % ft_strlen(base)]), count);
}
