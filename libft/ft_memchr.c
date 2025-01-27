/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:16 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/20 11:53:41 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;

	if (s != NULL)
	{
		ptr = (const char *)s;
		while (n--)
		{
			if (*ptr == (char)c)
				return ((char *)ptr);
			ptr++;
		}
	}
	return (NULL);
}
