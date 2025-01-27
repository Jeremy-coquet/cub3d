/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:28:46 by gudoyle           #+#    #+#             */
/*   Updated: 2024/03/08 08:36:46 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_pf(const char *type, unsigned long long n, size_t *count)
{
	char	*str_u;
	char	*str_l;

	if (!type)
		return ;
	str_u = "0123456789ABCDEF";
	str_l = "0123456789abcdef";
	if (*type == 'X')
		ft_putnbr_base_pf(str_u, n, count);
	if (*type == 'x')
		ft_putnbr_base_pf(str_l, n, count);
}
