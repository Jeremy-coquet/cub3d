/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:02:56 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 07:52:23 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_reles(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		mlx->player->left_right = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		mlx->player->left_right = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		mlx->player->up_down = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		mlx->player->up_down = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		mlx->player->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		mlx->player->rot = 0;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		mlx->player->player_speed = PLAYER_SPEED;
}

static void	rotate_player(t_mlx *mlx, int i)
{
	if (i == 1)
	{
		mlx->player->angle += ROTATION_SPEED;
		if (mlx->player->angle > 2 * M_PI)
			mlx->player->angle -= 2 * M_PI;
	}
	else
	{
		mlx->player->angle -= ROTATION_SPEED;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * M_PI;
	}
}

static void	move_player(t_mlx *mlx, double move_x, double move_y)
{
	int	map_grid_y;
	int	map_grid_x;
	int	new_x;
	int	new_y;

	new_x = roundf(mlx->player->player_x + move_x);
	new_y = roundf(mlx->player->player_y + move_y);
	map_grid_x = (new_x / TILE_SIZE);
	map_grid_y = (new_y / TILE_SIZE);
	if (mlx->data->map2d[map_grid_y][map_grid_x] != '1' && \
	(mlx->data->map2d[map_grid_y][(int)(mlx->player->player_x + move_x * 3)
	/ TILE_SIZE] != '1' &&
	mlx->data->map2d[(int)(mlx->player->player_y + move_y * 3)
	/ TILE_SIZE][map_grid_x] != '1'))
	{
		mlx->player->player_x = new_x;
		mlx->data->p_x = new_x / TILE_SIZE;
		mlx->player->player_y = new_y;
		mlx->data->p_y = new_y / TILE_SIZE;
	}
}

void	hook(t_mlx *mlx, double move_x, double move_y)
{
	if (mlx->player->rot == 1)
		rotate_player(mlx, 1);
	if (mlx->player->rot == -1)
		rotate_player(mlx, 0);
	if (mlx->player->left_right == 1)
	{
		move_x = -sin(mlx->player->angle) * mlx->player->player_speed;
		move_y = cos(mlx->player->angle) * mlx->player->player_speed;
	}
	if (mlx->player->left_right == -1)
	{
		move_x = sin(mlx->player->angle) * mlx->player->player_speed;
		move_y = -cos(mlx->player->angle) * mlx->player->player_speed;
	}
	if (mlx->player->up_down == 1)
	{
		move_x = cos(mlx->player->angle) * mlx->player->player_speed;
		move_y = sin(mlx->player->angle) * mlx->player->player_speed;
	}
	if (mlx->player->up_down == -1)
	{
		move_x = -cos(mlx->player->angle) * mlx->player->player_speed;
		move_y = -sin(mlx->player->angle) * mlx->player->player_speed;
	}
	move_player(mlx, move_x, move_y);
}
