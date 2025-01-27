/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:33 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/15 15:10:38 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if ((src != NULL) && (dstsize > 0))
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// #include<string.h>

// int	main(void) {
// 	char destination[6]; // Tampon de destination de taille  100
// 	const char source[] = "Ceci est une chaîne source."; // Chaîne source
// 	size_t taille_destination = sizeof(destination); //
// 	size_t longueur_source = ft_strlcpy(destination, source, 28);
// 	printf("La longueur de la chaîne source est : %zu\n", longueur_source);

// 	printf("Le contenu du tampon de destination est : %s\n", destination);
// 	return  0;
// }