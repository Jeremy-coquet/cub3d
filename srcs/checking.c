/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:04:46 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 08:04:39 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_file_name(char *file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (file[i] == '.'
			&& file[i + 1] == 'c'
			&& file[i + 2] == 'u'
			&& file[i + 3] == 'b'
			&& file[i + 4] == '\0')
			return (true);
	}
	return (false);
}

static bool	check_permission_file(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perror("failed to open this"), false);
	close(fd);
	return (true);
}

bool	checking(char *file, t_data *data)
{
	int	count;

	if (!check_file_name(file))
		return (ft_putendl_fd("Invalid file extension", 2), false);
	if (!(check_permission_file(file)))
		return (ft_putendl_fd("Invalid file permissions", 2), false);
	count = check_config(file);
	if (count == -1)
		return (ft_putendl_fd(INVALID_CONFIG, 2), false);
	if ((!check_and_set_map(file, count, data)))
		return (ft_putendl_fd(INVALID_MAP, 2), false);
	return (true);
}
