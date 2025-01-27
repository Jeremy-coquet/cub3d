/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:39 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/19 13:28:29 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	i = 0;
	if (s != NULL)
	{
		i = ft_strlen((char *)s);
		ptr = s;
		while (*ptr)
			ptr++;
		if ((unsigned char)c == '\0')
			return ((char *)ptr);
		while (i >= 0)
		{
			if (*ptr == (unsigned char)c)
				return ((char *)ptr);
			ptr--;
			i--;
		}
	}
	return (NULL);
}
