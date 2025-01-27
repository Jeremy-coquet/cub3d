/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:52:59 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 13:36:36 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, unsigned long color)
{
	if (x < 0 || x >= WIDTH)
		return ;
	if (y < 0 || y >= HEIGHT)
		return ;
	mlx_put_pixel(mlx->img, x, y, color);
}

float	cast_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

mlx_texture_t	*get_texture(t_mlx *mlx, int flag)
{
	mlx->ray->ray_ngl = cast_angle(mlx->ray->ray_ngl);
	if (flag == 0)
	{
		if (mlx->ray->ray_ngl > (M_PI / 2)
			&& mlx->ray->ray_ngl < (3 * M_PI / 2))
			return (mlx->data->ea);
		else
			return (mlx->data->we);
	}
	else
	{
		if ((mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI))
			return (mlx->data->so);
		else
			return (mlx->data->no);
	}
}

int	get_x_tex(mlx_texture_t *texture, t_mlx *mlx)
{
	int	x_tex;

	if (mlx->ray->flag == 1)
		x_tex = (int)fmodf((mlx->ray->horizontal_x * \
		(texture->width / TILE_SIZE)), texture->width);
	else
		x_tex = (int)fmodf((mlx->ray->vertical_y * \
		(texture->width / TILE_SIZE)), texture->width);
	return (x_tex);
}

unsigned long	reverse_bytes(unsigned long c)
{
	unsigned long	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}
