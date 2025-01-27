/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:41:02 by gudoyle           #+#    #+#             */
/*   Updated: 2024/10/07 14:25:06 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	if (!s[i])
		return (0);
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

// Alloue (avec malloc(3)) et retourne un tableau
// de chaînes de caractères obtenu en séparant ’s’ à
// l’aide du caractère ’c’, utilisé comme délimiteur.
// Le tableau doit être terminé par NULL.

// int	main(void)
// {
// 	char		**ptr;
// 	char const	*s;
// 	char		c;
// 	int			i;

// 	i = 0;
// 	s = "hello!";
// 	c = ' ';
// 	ptr = ft_split(s, c);
// 	while (ptr[i])
// 	{
// 		printf("%s\n", ptr[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (ptr[i])
// 	{
// 		free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// }
