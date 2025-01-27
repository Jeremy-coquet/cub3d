/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:48:28 by gudoyle           #+#    #+#             */
/*   Updated: 2024/03/08 08:37:08 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_pf(char *str, size_t *count)
{
	if (!str)
		str = "(null)";
	write(1, str, ft_strlen(str));
	*count += ft_strlen(str);
}
