/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:28 by gudoyle           #+#    #+#             */
/*   Updated: 2024/10/07 14:49:54 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	if (s1 != NULL)
	{
		size = ft_strlen(s1);
		copy = (char *)malloc((sizeof(char) * size) + 1);
		if (!copy)
			return (NULL);
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}
