/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 07:53:15 by jcoquet           #+#    #+#             */
/*   Updated: 2024/11/14 15:26:46 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*ft_total_storage(int fd, char *storage, char *buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(storage);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!storage)
			storage = ft_strdup("");
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

static char	*ft_split_storage(char *line)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	left_c = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = (NULL);
	}
	line[i + 1] = '\0';
	return (left_c);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*storage;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || !buffer)
	{
		free(storage);
		free(buffer);
		storage = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = ft_total_storage(fd, storage, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	storage = ft_split_storage(line);
	return (line);
}

// int	main(void)
// {
// 	ssize_t	fd;
// 	char	*line;
// 	int		i;

// 	i = 3;
// 	fd = open("test.txt", O_RDONLY);
// 	while (i > 0)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		i--;
// 		free(line);
// 	}
// 	return (0);
// }
