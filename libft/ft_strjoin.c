/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:41:09 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/20 08:59:26 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*str;
	int		str_len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	b = 0;
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((sizeof(char) * str_len) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		str[i + b] = s2[b];
		b++;
	}
	str[i + b] = '\0';
	return (str);
}
