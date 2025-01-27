/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:50:46 by gudoyle           #+#    #+#             */
/*   Updated: 2024/11/28 10:57:41 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*trim_texture(char *line)
{
	char	*tmp;
	char	*re;

	tmp = ft_strtrim(line, "\n");
	re = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strtrim(re, "	");
	free(re);
	re = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strtrim(re, " ");
	free(re);
	re = ft_strdup(tmp);
	free (tmp);
	return (re);
}

static void	set_textures(char *line, t_data *data)
{
	char	*tmp;

	if (line && *line)
	{
		tmp = trim_texture(line + 2);
		while (line && (*line == ' ' || *line == '	'))
			line++;
		if (!ft_strncmp(line, "NO", 2))
			data->no = mlx_load_png(tmp);
		else if (!ft_strncmp(line, "SO", 2))
			data->so = mlx_load_png(tmp);
		else if (!ft_strncmp(line, "WE", 2))
			data->we = mlx_load_png(tmp);
		else if (!ft_strncmp(line, "EA", 2))
			data->ea = mlx_load_png(tmp);
		free(tmp);
	}
	return ;
}

static void	set_colors(char *line, t_data *data)
{
	if (line && *line)
	{
		while (line && (*line == ' ' || *line == '	'))
			line++;
		if (!ft_strncmp(line, "F", 1))
			data->f = rgb_to_hex(line + 1);
		else if (!ft_strncmp(line, "C", 1))
			data->c = rgb_to_hex(line + 1);
	}
	return ;
}

static void	set_map_name(char *file, t_data *data)
{
	char	*tmp;

	tmp = ft_strrchr(file, '/');
	if (tmp && *tmp == '/')
		tmp++;
	tmp = ft_strtrim(tmp, ".cub");
	data->map_name = ft_strdup(tmp);
	free(tmp);
}

bool	set_parameters(char *file, t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp;

	tmp = ft_strdup("");
	line = tmp;
	free(tmp);
	fd = open(file, O_RDONLY);
	set_map_name(file, data);
	while ((line != NULL))
	{
		line = get_next_line(fd);
		set_textures(line, data);
		set_colors(line, data);
		free(line);
	}
	if (data->ea == NULL || data->we == NULL || data->so == NULL \
	|| data->no == NULL)
		return (close(fd), false);
	return (close(fd), true);
}
