/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:05:02 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 07:53:41 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_line(char *path_file, int count, int *flags)
{
	char	*line;
	int		fd;

	line = "";
	fd = open(path_file, O_RDONLY);
	while ((line != NULL))
	{
		line = get_next_line(fd);
		if (!check_line(line, flags))
		{
			free(line);
			break ;
		}
		count++;
		if (check_flags(flags) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (close(fd), count);
}

int	check_config(char *path_file)
{
	int		*flags;
	int		count;

	count = 0;
	flags = ft_calloc(7, sizeof(int));
	count = count_line(path_file, count, flags);
	if (check_flags(flags) == 1)
		return (ft_putendl_fd("Missing a config", 2), free(flags), -1);
	if (check_flags(flags) == 3)
		return (ft_putendl_fd("Duplicated config", 2), free(flags), -1);
	return (free(flags), count);
}
