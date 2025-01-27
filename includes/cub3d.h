/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:55:52 by gudoyle           #+#    #+#             */
/*   Updated: 2024/12/04 08:08:38 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// dimentions
# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 800
# define FOV 90
# define ROTATION_SPEED 0.060
# define ROTATION_SPEED_MOUSE 0.001
# define PLAYER_SPEED 107

// long str
# define INVALID_CONFIG "Invalid config\n\
NO ./path_to_the_north_texture\n\
SO ./path_to_the_south_texture\n\
WE ./path_to_the_west_texture\n\
EA ./path_to_the_east_texture\n\
F Red(0-255), Green(0-255), Blue(0-255)\n\
C Red(0-255), Green(0-255), Blue(0-255)\n\
Map"
# define INVALID_MAP "La map doit être composée d’uniquement \
ces 6 caractères : 0 pour les planchés, \
1 pour les murs, et N,S,E ou W qui représentent la position de départ \
du joueur et son orientation. \
Le joueur ne doit pas pouvoir accèder à des espaces vides."

//********************STRUCTS*****************

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	int		player_x; // player x position in pixels
	int		player_y; // player y position in pixels
	double	angle;
	float	fov_rd;
	int		rot;
	int		left_right;
	int		up_down;
	int		player_speed;
}	t_player;

typedef struct s_ray
{
	int		index;
	double	ray_ngl;
	double	distance; // distance to the wall
	int		flag; // flag for the wall
	int		horizontal_x;
	int		horizontal_y;
	int		vertical_x;
	int		vertical_y;
}	t_ray;

typedef struct s_data
{
	char			**map2d;
	char			*map_name;
	int				p_x; // player x position in the map
	int				p_y; // player y position in the map
	int				w_map;
	int				h_map;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	unsigned long	f;
	unsigned long	c;
	bool			cursor;
}	t_data;

typedef struct s_mlx
{
	void		*win;
	void		*img;
	void		*minimap_img;
	void		*mlx_p;
	t_ray		*ray;
	t_data		*data;
	t_player	*player;
}	t_mlx;

//********************PROTOTYPE***************

/////////////////// KEYBINDINGS /////////////////
void			mlx_key(mlx_key_data_t keydata, void *ml); // key press
void			cursor_fonction(double xpos, double ypos, void *ml);
void			mouse_mouvements(mouse_key_t button, action_t action,
					modifier_key_t mods, void *ml);

/////////////////// CHECKING /////////////////
bool			checking(char *file, t_data *data);

///////////////// CUB3D /////////////////////
int				run_game(t_mlx *mlx);

///////////////// SETTING //////////////////
bool			set_parameters(char *file, t_data *data);
char			*trim_texture(char *line);

////////////// CHECK_CONFIG //////////////////
int				check_config(char *file);

////////////// CHECK_CONFIG_UTILS //////////////////
bool			check_line(char *str, int *flags);
int				check_flags(int *flags);

/////////////// CHECK_MAP ///////////////////
bool			check_and_set_map(char *path_file, int count, t_data *data);

/////////////// CHECK_MAP_UTILS ///////////////////
bool			char_is_valid(char c);
bool			multiple_start_pos(int *pos_flag, char c);
bool			map_has_valid_chars(char **tmp_map);
bool			map_has_valid_design(char **tmp_map, t_data *data);

///////////////////// RAY_CASTING //////////////////
void			cast_rays(t_mlx *mlx);

///////////////////// RAY_CASTING_UTILS //////////////////
int				unit_circle(float angle, char c);
int				wall_hit(float x, float y, t_mlx *mlx);
int				inter_check(float angle, float *inter, float *step,
					int is_horizon);
float			get_h_inter(t_mlx *mlx, float angl);
float			get_v_inter(t_mlx *mlx, float angl);

/////////////////// RENDERING //////////////////////
void			render_wall(t_mlx *mlx, int ray);

/////////////////// RENDERING_UTILS //////////////////////
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, unsigned long color);
float			cast_angle(float angle);
mlx_texture_t	*get_texture(t_mlx *mlx, int flag);
int				get_x_tex(mlx_texture_t *texture, t_mlx *mlx);
unsigned long	reverse_bytes(unsigned long c);

////////////////////// FLOOD FILL ////////////////////////
int				flood_fill(char **tab, t_point size, t_point begin,
					t_data *data);

////////////////////// MOVEMENTS ////////////////////////
void			ft_reles(mlx_key_data_t keydata, t_mlx *mlx);
void			hook(t_mlx *mlx, double move_x, double move_y);

////////////////////// UTILS ////////////////////////
bool			check_isdigit(char **rgb_char);
void			free_mlx(t_mlx *mlx);
void			free_tab(char **tab);
void			ft_exit(t_mlx *mlx);
unsigned int	rgb_to_hex(char *line);
#endif