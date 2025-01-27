/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:04:42 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 08:04:51 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_mlx *mlx)
{
	char	c;

	c = mlx->data->map2d[mlx->data->p_y][mlx->data->p_x];
	if (c == 'N')
		mlx->player->angle = 3 * M_PI / 2;
	else if (c == 'S')
		mlx->player->angle = M_PI / 2;
	else if (c == 'W')
		mlx->player->angle = M_PI;
	else if (c == 'E')
		mlx->player->angle = 0;
	mlx->player->player_x = mlx->data->p_x * TILE_SIZE + TILE_SIZE / 2;
	mlx->player->player_y = mlx->data->p_y * TILE_SIZE + TILE_SIZE / 2;
	mlx->player->fov_rd = (FOV * M_PI) / 180;
}

static void	draw_minimap(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y / 6 <= mlx->data->h_map)
	{
		while (x / 6 <= mlx->data->w_map && mlx->data->map2d[y / 6][x / 6])
		{
			if (mlx->data->map2d[y / 6][x / 6] == '1'
				|| mlx->data->map2d[y / 6][x / 6] == '\0')
				my_mlx_pixel_put(mlx, x, y, 0xFFFFFF00);
			else
			{
				if (y / 6 == mlx->data->p_y && x / 6 == mlx->data->p_x)
					my_mlx_pixel_put(mlx, x, y, mlx->data->c);
				else if (ft_strchr("0ENSW ", mlx->data->map2d[y / 6][x / 6]))
					my_mlx_pixel_put(mlx, x, y, mlx->data->f);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static void	draw_map_loop(void *mlxl)
{
	t_mlx	*mlx;

	mlx = mlxl;
	mlx_delete_image(mlx->mlx_p, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_p, WIDTH, HEIGHT);
	hook(mlx, 0, 0);
	cast_rays(mlx);
	mlx_image_to_window(mlx->mlx_p, mlx->img, 0, 0);
	mlx_delete_image(mlx->mlx_p, mlx->minimap_img);
	mlx->minimap_img = mlx_new_image(mlx->mlx_p, WIDTH / 6, HEIGHT / 6);
	draw_minimap(mlx);
	mlx_image_to_window(mlx->mlx_p, mlx->minimap_img, 0, 0);
}

int	run_game(t_mlx *mlx)
{
	if (HEIGHT > 1440 || WIDTH > 2560 || FOV > 160 || FOV <= 0
		|| HEIGHT < mlx->data->h_map * 12 || WIDTH < mlx->data->w_map * 12)
		return (ft_putendl_fd("Wrong size", 2), EXIT_FAILURE);
	mlx->mlx_p = mlx_init(WIDTH, HEIGHT, mlx->data->map_name, false);
	if (!mlx->mlx_p)
		return (ft_putendl_fd("mlp_p null", 2), EXIT_FAILURE);
	init_player(mlx);
	mlx_loop_hook(mlx->mlx_p, &draw_map_loop, mlx);
	mlx_key_hook(mlx->mlx_p, &mlx_key, mlx);
	mlx_mouse_hook(mlx->mlx_p, &mouse_mouvements, mlx);
	mlx_loop(mlx->mlx_p);
	return (EXIT_SUCCESS);
}
