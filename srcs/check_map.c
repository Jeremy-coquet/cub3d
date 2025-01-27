/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:04:51 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 08:04:49 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**malloc_map(char *path_file, int count)
{
	int		fd;
	char	*line;
	char	**tmp_map;
	char	*tmp;

	tmp = ft_strdup("");
	line = tmp;
	free(tmp);
	fd = open(path_file, O_RDONLY);
	while (count-- > 0)
	{
		tmp = get_next_line(fd);
		free(tmp);
	}
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		count++;
	}
	tmp_map = ft_calloc(count + 1, sizeof(char *));
	if (!tmp_map)
		return (close (fd), printf("Malloc error"), NULL);
	return (close(fd), tmp_map);
}

static int	store_map(char **tmp_map, char *path_file, int count)
{
	int		fd;
	char	*line;
	char	*tmp;

	tmp = ft_strdup("");
	line = tmp;
	free(tmp);
	fd = open(path_file, O_RDONLY);
	while (count-- > 0)
	{
		tmp = get_next_line(fd);
		free(tmp);
	}
	while (line)
	{
		line = get_next_line(fd);
		*tmp_map = ft_strdup(line);
		tmp_map++;
		free(line);
	}
	return (EXIT_SUCCESS);
}

static void	get_map_width_height(char **map, t_data *data)
{
	int	x;
	int	y;

	data->w_map = 0;
	data->h_map = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		if (y > data->h_map)
			data->h_map = y;
		while (map[y][x])
		{
			if (x > data->w_map)
				data->w_map = x;
			if (ft_strchr("WENS", map[y][x]))
			{
				data->p_x = x;
				data->p_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static bool	check_map_size(t_data *data)
{
	if (data->w_map > 100 || data->h_map > 60)
		return (false);
	return (true);
}

bool	check_and_set_map(char *path_file, int count, t_data *data)
{
	char	**tmp_map;

	tmp_map = malloc_map(path_file, count);
	store_map(tmp_map, path_file, count);
	if (!map_has_valid_chars(tmp_map))
		return (free_tab(tmp_map), false);
	get_map_width_height(tmp_map, data);
	if (!check_map_size(data))
		return (free_tab(tmp_map),
			ft_putendl_fd("Max width 100 | Max hight 60", 2), false);
	if (!map_has_valid_design(tmp_map, data))
		return (free_tab(tmp_map),
			ft_putendl_fd("invalid map design", 2), false);
	data->map2d = malloc_map(path_file, count);
	store_map(data->map2d, path_file, count);
	free_tab(tmp_map);
	return (true);
}
