/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:26 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/19 13:24:59 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	if (s != NULL)
	{
		ptr = s;
		while (*ptr)
		{
			if (*ptr == (unsigned char)c)
				return ((char *)ptr);
			ptr++;
		}
		if ((unsigned char)c == '\0')
			return ((char *)ptr);
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s;
// 	int			c;

// 	s = "je pu du cul";
// 	c = 'c' + 256;
// 	printf("%s", ft_strchr(s, c));
// 	return (0);
// }
