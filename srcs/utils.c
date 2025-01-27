/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:52:35 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/02 12:18:40 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_isdigit(char **rgb_char)
{
	int	i;
	int	y;

	i = 0;
	while (rgb_char && rgb_char[i])
	{
		y = 0;
		while (rgb_char[i][y] && rgb_char[i][y] == ' ')
			y++;
		while (rgb_char[i][y] && ft_isdigit(rgb_char[i][y]))
			y++;
		while (rgb_char[i][y] && rgb_char[i][y] == ' ')
			y++;
		if (rgb_char[i][y] && (rgb_char[i][y] == '\0'
			|| rgb_char[i][y] != '\n'))
			return (false);
		i++;
	}
	return (true);
}

void	free_mlx(t_mlx *mlx)
{
	free_tab(mlx->data->map2d);
	if (mlx->data->map_name)
		free(mlx->data->map_name);
	if (mlx->player)
		free(mlx->player);
	if (mlx->ray)
		free(mlx->ray);
	if (mlx->data)
		free(mlx->data);
	if (mlx->data->no)
		mlx_delete_texture(mlx->data->no);
	if (mlx->data->ea)
		mlx_delete_texture(mlx->data->ea);
	if (mlx->data->so)
		mlx_delete_texture(mlx->data->so);
	if (mlx->data->we)
		mlx_delete_texture(mlx->data->we);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
}

void	ft_exit(t_mlx *mlx)
{
	free_mlx(mlx);
	exit(0);
}

unsigned int	rgb_to_hex(char *line)
{
	char			*tmp;
	char			**tmp2;
	unsigned int	*integer;
	int				i;
	unsigned long	re;

	integer = ft_calloc(1, sizeof(unsigned int *));
	i = 0;
	tmp = trim_texture(line);
	tmp2 = ft_split(tmp, ',');
	free(tmp);
	while (tmp2 && tmp2[i] && i < 3)
	{
		while (line && (*line == ' ' || *line == '	'))
			line++;
		integer[i] = ft_atoi(tmp2[i]);
		i++;
	}
	i = 0;
	free_tab(tmp2);
	re = (uint32_t)integer[0] << 24 | (uint32_t)integer[1] << 16 | \
		(uint32_t)integer[2] << 8 | (uint32_t)0xFF;
	free(integer);
	return (re);
}
