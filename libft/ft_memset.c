/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:24 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/19 11:36:12 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if (!b)
		return (NULL);
	ptr = (unsigned char *) b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	b = ptr;
	return (b);
}
