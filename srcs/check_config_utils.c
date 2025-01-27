/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:05:02 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 08:05:42 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	count_virgule(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i++])
	{
		if (str[i] == ',')
			count++;
	}
	if (count != 2)
		return (false);
	return (true);
}

static bool	check_colors(char *str, int index, int *flags)
{
	char	**rgb_char;
	int		red;
	int		green;
	int		blue;
	int		i;

	i = 0;
	str++;
	if (!count_virgule(str))
		return (ft_putendl_fd("Invalid color", 2), false);
	rgb_char = ft_split(str, ',');
	if (!rgb_char || !rgb_char[0] || !rgb_char[1] || !rgb_char[2]
		|| !check_isdigit(rgb_char) || rgb_char[3])
		return (free_tab(rgb_char), ft_putendl_fd("Invalid color", 2), false);
	red = ft_atoi(rgb_char[0]);
	green = ft_atoi(rgb_char[1]);
	blue = ft_atoi(rgb_char[2]);
	free_tab(rgb_char);
	if (red > 255 || green > 255 || blue > 255)
		return (ft_putendl_fd("Invalid color", 2), false);
	if (red < 0 || green < 0 || blue < 0)
		return (ft_putendl_fd("Invalid color", 2), false);
	flags[index]++;
	return (true);
}

int	check_flags(int *flags)
{
	int		i;

	i = 0;
	while (i <= 5)
	{
		if (flags[i] > 1)
			return (3);
		if (flags[i] < 1)
			return (1);
		i++;
	}
	return (0);
}

static bool	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
			return (false);
		i++;
	}
	return (true);
}

bool	check_line(char *str, int *flags)
{
	if (str && *str)
	{
		while (str && (*str == ' ' || *str == '	'))
			str++;
		if (!ft_strncmp(str, "NO", 2))
			return (flags[0]++, true);
		else if (!ft_strncmp(str, "SO", 2))
			return (flags[1]++, true);
		else if (!ft_strncmp(str, "WE", 2))
			return (flags[2]++, true);
		else if (!ft_strncmp(str, "EA", 2))
			return (flags[3]++, true);
		else if (!ft_strncmp(str, "F", 1))
			return (check_colors(str, 4, flags));
		else if (!ft_strncmp(str, "C", 1))
			return (check_colors(str, 5, flags));
		else if (*str != '\n' && !check_flags(flags))
			return (false);
		else if (!is_empty(str))
			return (false);
	}
	return (true);
}
