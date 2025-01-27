/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:57:40 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 07:52:27 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_rays(t_mlx *mlx)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	mlx->ray->ray_ngl = mlx->player->angle - (mlx->player->fov_rd / 2);
	while (ray < WIDTH)
	{
		mlx->ray->flag = 0;
		h_inter = get_h_inter(mlx, cast_angle(mlx->ray->ray_ngl));
		v_inter = get_v_inter(mlx, cast_angle(mlx->ray->ray_ngl));
		if (v_inter <= h_inter)
			mlx->ray->distance = v_inter;
		else
		{
			mlx->ray->distance = h_inter;
			mlx->ray->flag = 1;
		}
		if (v_inter == 0 || h_inter == 0)
			break ;
		render_wall(mlx, ray);
		ray++;
		mlx->ray->ray_ngl += (mlx->player->fov_rd / WIDTH);
	}
}
