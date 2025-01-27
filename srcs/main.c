/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:04:30 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 07:52:21 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_struct(t_mlx *mlx)
{
	mlx->data = ft_calloc(1, sizeof(t_data));
	mlx->ray = ft_calloc(1, sizeof(t_ray));
	mlx->player = ft_calloc(1, sizeof(t_player));
	mlx->player->player_speed = PLAYER_SPEED;
}

int	main(int ac, char **av)
{
	t_mlx		mlx;

	(void)av;
	if (ac == 2)
	{
		init_struct(&mlx);
		if (!(checking(av[1], mlx.data)))
			return (free_mlx(&mlx), EXIT_FAILURE);
		if (!(set_parameters(av[1], mlx.data)))
			return (free_mlx(&mlx), EXIT_FAILURE);
		if (!run_game(&mlx))
			return (free_mlx(&mlx), EXIT_FAILURE);
		return (free_mlx(&mlx), EXIT_FAILURE);
	}
	return (ft_putendl_fd("insert map file path in argument", 2), EXIT_FAILURE);
}
