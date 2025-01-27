/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:57:40 by gudoyle           #+#    #+#             */
/*   Updated: 2024/11/27 08:02:40 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(float x, float y, t_mlx *mlx)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= mlx->data->h_map || x_m >= mlx->data->w_map))
		return (0);
	if (mlx->data->map2d[y_m] && x_m <= (int)ft_strlen(mlx->data->map2d[y_m]))
		if (mlx->data->map2d[y_m][x_m] == '1')
			return (0);
	return (1);
}

float	get_h_inter(t_mlx *mlx, float angl)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(mlx->player->player_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = mlx->player->player_x + (h_y - mlx->player->player_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || \
	(!unit_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, mlx))
	{
		h_x += x_step;
		h_y += y_step;
	}
	mlx->ray->horizontal_x = h_x;
	mlx->ray->horizontal_y = h_y;
	return (sqrt(pow(h_x - mlx->player->player_x, 2) + \
	pow(h_y - mlx->player->player_y, 2)));
}

float	get_v_inter(t_mlx *mlx, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(mlx->player->player_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, false);
	v_y = mlx->player->player_y + (v_x - mlx->player->player_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || \
	(!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, mlx))
	{
		v_x += x_step;
		v_y += y_step;
	}
	mlx->ray->vertical_x = v_x;
	mlx->ray->vertical_y = v_y;
	return (sqrt(pow(v_x - mlx->player->player_x, 2) + \
	pow(v_y - mlx->player->player_y, 2)));
}
