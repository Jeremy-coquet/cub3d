/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:31:16 by gudoyle           #+#    #+#             */
/*   Updated: 2024/03/08 08:36:56 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_pf(void *ptr, size_t *count)
{
	const char	*type;

	type = "x";
	ft_putstr_pf("0x", count);
	ft_puthex_pf(type, (unsigned long long)ptr, count);
}
