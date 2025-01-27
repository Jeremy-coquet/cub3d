/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:20:03 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/15 10:52:52 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl *= -1;
	}
	if (nbl >= 10)
	{
		ft_putnbr_fd((nbl / 10), fd);
		ft_putnbr_fd((nbl % 10), fd);
	}
	else
		ft_putchar_fd((nbl + '0'), fd);
}
