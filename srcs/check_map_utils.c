/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:04:58 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/02 10:57:46 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	char_is_valid(char c)
{
	if (c == ' ' || c == '1' || c == '0'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '\n')
		return (true);
	return (ft_putendl_fd("Invalid char detected in the map", 2), false);
}

bool	multiple_start_pos(int *pos_flag, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		(*pos_flag)++;
	if (*pos_flag > 1)
		return (ft_putendl_fd("Multiple spawn location detected", 2), true);
	return (false);
}

bool	map_has_valid_chars(char **tmp_map)
{
	int	y;
	int	x;
	int	pos_flag;

	y = 0;
	x = 0;
	pos_flag = 0;
	while (tmp_map && tmp_map[y])
	{
		while (tmp_map && tmp_map[y][x])
		{
			if (!char_is_valid(tmp_map[y][x])
				|| multiple_start_pos(&pos_flag, tmp_map[y][x]))
				return (false);
			x++;
		}
		x = 0;
		y++;
	}
	if (pos_flag == 0)
		return (ft_putendl_fd("No spawn location detected", 2), false);
	return (true);
}

bool	map_has_valid_design(char **tmp_map, t_data *data)
{
	t_point	player_pos;
	t_point	map_size;

	player_pos.x = data->p_x;
	player_pos.y = data->p_y;
	map_size.x = data->w_map;
	map_size.y = data->h_map;
	if (flood_fill(tmp_map, map_size, player_pos, data) != 0)
		return (false);
	return (true);
}
