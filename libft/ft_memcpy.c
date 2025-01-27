/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:20 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/20 12:14:17 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_cpy;
	char		*dst_cpy;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	src_cpy = (const char *)src;
	dst_cpy = (char *)dst;
	while (n--)
		dst_cpy[n] = src_cpy[n];
	return (dst);
}
