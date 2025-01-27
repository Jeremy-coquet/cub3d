/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:31 by gudoyle           #+#    #+#             */
/*   Updated: 2024/02/16 11:36:36 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	size_t		dst_len;
	size_t		i;

	if (!src || !dst)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i] && dstsize > (dst_len + i + 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	return (src_len + dst_len);
}

// int main() {
//     char dst[15] = "";
//     const char *src = "";
//     size_t dstsize = sizeof(dst);
//     size_t result;

//     result = strlcat(dst, src, dstsize);

//     printf("Resulting string: %s\n", dst);
//     printf("Total length of the resulting string: %zu\n", result);

//     return  0;
// }