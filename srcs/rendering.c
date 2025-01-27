/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:52:59 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/02 11:25:54 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_floor_ceiling(t_mlx *mlx, int ray, int t_pix, int b_pix)
{
	int		i;

	i = b_pix;
	while (i < HEIGHT)
		my_mlx_pixel_put(mlx, ray, i++, mlx->data->f);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(mlx, ray, i++, mlx->data->c);
}

static void	draw_wall(t_mlx *mlx, int t_pix, int b_pix, double wall_h)
{
	double				x_tex;
	double				y_tex;
	mlx_texture_t		*texture;
	unsigned int		*arr;
	double				factor;

	texture = get_texture(mlx, mlx->ray->flag);
	arr = (unsigned int *)texture->pixels;
	factor = (double)texture->height / wall_h;
	x_tex = get_x_tex(texture, mlx);
	y_tex = (t_pix - (HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_tex < 0)
		y_tex = 0;
	while (t_pix < b_pix)
	{
		my_mlx_pixel_put(mlx, mlx->ray->index, t_pix, \
		reverse_bytes(arr[(int)y_tex * texture->width + (int)x_tex]));
		y_tex += factor;
		t_pix++;
	}
}

void	render_wall(t_mlx *mlx, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	mlx->ray->distance *= cos(cast_angle(mlx->ray->ray_ngl \
		- mlx->player->angle));
	wall_h = (TILE_SIZE / mlx->ray->distance) * \
			((WIDTH / 2) / tan(mlx->player->fov_rd / 2));
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	mlx->ray->index = ray;
	draw_wall(mlx, t_pix, b_pix, wall_h);
	draw_floor_ceiling(mlx, ray, t_pix, b_pix);
}
