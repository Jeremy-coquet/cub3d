/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:41:48 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/02 08:14:10 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	fill(char **tab, t_point size, t_point cur, t_data *data)
{
	int		re;

	re = 0;
	if (cur.y < 0 || cur.y > size.y || cur.x < 0 || cur.x > size.x
		|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F')
		return (0);
	if ((cur.y == 0 && ft_strchr("0WENS", tab[cur.y][cur.x]))
		|| (cur.x == 0 && ft_strchr("0WENS", tab[cur.y][cur.x]))
			|| (cur.y == (size.y) && ft_strchr("0WENS", tab[cur.y][cur.x])))
		return (1);
	if (ft_strchr("0WENS", tab[cur.y][cur.x]))
	{
		tab[cur.y][cur.x] = 'F';
		re += fill(tab, size, (t_point){cur.x - 1, cur.y}, data);
		re += fill(tab, size, (t_point){cur.x + 1, cur.y}, data);
		re += fill(tab, size, (t_point){cur.x, cur.y - 1}, data);
		re += fill(tab, size, (t_point){cur.x, cur.y + 1}, data);
		if (cur.x + 1 > data->w_map)
			data->w_map = cur.x + 1;
		if (cur.y + 1 > data->h_map)
			data->h_map = cur.y + 1;
		return (re);
	}
	return (1);
}

int	flood_fill(char **tab, t_point size, t_point begin, t_data *data)
{
	char	re;

	re = 0;
	data->w_map = 0;
	data->h_map = 0;
	re = fill(tab, size, begin, data);
	return (re);
}
