/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:50:38 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/21 16:51:04 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_staff_count
{
	int				exit_s;
	int				collectible_s;
}					t_staff_count;

typedef struct s_count
{
	int				pace;
	int				exit;
	int				enemy;
}					t_count;

typedef struct s_content
{
	char			wall;
	char			exit;
	char			space;
	char			enemy;
	char			player;
	char			fire_ball;
	char			collectible;
}					t_content;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_image
{
	void			*image;
	char			*path;
	int				width;
	int				height;
}					t_image;

typedef struct s_map_dup
{
	char			**grid;
	size_t			rows;
	size_t			cols;
}					t_map_dup;

typedef struct s_map
{
	char			**grid;
	size_t			rows;
	size_t			cols;
}					t_map;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*mlx_win;

	t_image			wall;
	t_image			exit;
	t_image			floor;
	t_image			enemy;
	t_image			player;
	t_image			fire_ball;
	t_image			collectible;
	t_image			pace_counter;

	t_pos			wall_p;
	t_pos			exit_p;
	t_pos			enemy_p;
	t_pos			floor_p;
	t_pos			player_p;
	t_pos			fire_ball_p;
	t_pos			collectible_p;
	t_pos			staff_p;

	t_content		content;
	t_count			count;

	t_staff_count	staff_count;

	int				exit_bool;

	t_map			ground;
	t_map_dup		map_dup;
}					t_mlx_data;

void				set_data(t_mlx_data *data);
void				check_content(t_mlx_data *data);
void				destroy_data(t_mlx_data *data);
void				display_content(t_mlx_data *data);
int					main_loop(t_mlx_data *data);
void				draw_image(t_mlx_data *data);
void				map_print(t_mlx_data *data);
void				input_action(int keycode, void *param);
void				render_top(t_mlx_data *data);
void				render_down(t_mlx_data *data);
void				render_left(t_mlx_data *data);
void				render_right(t_mlx_data *data);
void				change_player(t_mlx_data *data, char *new_image_path);
void				change_enemy(t_mlx_data *data, char *new_image_path);
void				move_enemy(t_mlx_data *data);
void				check_collision(t_mlx_data *data);
void				set_data_img(t_mlx_data *data);
int					map_init(char *map, t_mlx_data *data);
int					map_dup_init(char *map, t_mlx_data *data);
void				ft_exit(t_mlx_data *data, char *msg);
void				draw_map(t_mlx_data *data);
void				free_tab(t_mlx_data *data);
void				get_player(t_mlx_data *data);
void				get_enemy(t_mlx_data *data);
void				get_exit(t_mlx_data *data);
void				get_collectible(t_mlx_data *data);
void				map_checker(t_mlx_data *data, char *map);
void				collectible_count(t_mlx_data *data);
void				pace_counter(t_mlx_data *data);
void				move_fire_ball(t_mlx_data *data);
void				move_fire_ball_y(t_mlx_data *data);
void				move_fire_ball_x(t_mlx_data *data);
void				fd_checker(t_mlx_data *data, char *map);

#endif