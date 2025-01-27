/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybindings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:04:35 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 07:52:13 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_key(mlx_key_data_t keydata, void *ml)
{
	t_mlx	*mlx;

	mlx = ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		ft_exit(ml);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		mlx->player->left_right = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		mlx->player->left_right = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		mlx->player->up_down = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		mlx->player->up_down = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mlx->player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mlx->player->rot = 1;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		mlx->player->player_speed = PLAYER_SPEED * 2;
	ft_reles(keydata, mlx);
}

void	cursor_fonction(double xpos, double ypos, void *ml)
{
	t_mlx			*mlx;
	static double	last_xpos = -1;
	double			delta_x;

	mlx = ml;
	if (mlx->data->cursor)
		return ;
	(void)ypos;
	if (last_xpos == -1)
		last_xpos = xpos;
	delta_x = xpos - last_xpos;
	mlx->player->angle += delta_x * ROTATION_SPEED_MOUSE;
	last_xpos = xpos;
}

void	mouse_mouvements(mouse_key_t button, action_t action,
			modifier_key_t mods, void *ml)
{
	t_mlx	*mlx;

	mlx = ml;
	mlx->data->cursor = false;
	(void)action;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		mlx_set_cursor_mode(mlx->mlx_p, MLX_MOUSE_DISABLED);
		mlx_cursor_hook(mlx->mlx_p, &cursor_fonction, mlx);
	}
	if (button == MLX_MOUSE_BUTTON_RIGHT)
	{
		mlx_set_cursor_mode(mlx->mlx_p, MLX_MOUSE_NORMAL);
		mlx->data->cursor = true;
	}
}
