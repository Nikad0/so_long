/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:22:26 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/12 03:02:13 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	input_action(int keycode, void *param)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)param;
	if (keycode == 65307)
		destroy_data((t_mlx_data *)param);
	if (keycode == 119 || keycode == 65362)
		render_top(data);
	if (keycode == 115 || keycode == 65364)
		render_down(data);
	if (keycode == 97 || keycode == 65361)
		render_left(data);
	if (keycode == 100 || keycode == 65363)
		render_right(data);
}

void	render_top(t_mlx_data *data)
{
	int	new_pos_y;

	new_pos_y = (data->player_p.y) - 64;
	change_player(data, "./textures/player/up1.xpm");
	if (data->ground.grid[(new_pos_y) / 64][(data->player_p.x) / 64] != '1')
	{
		ft_printf("%d\n", data->count.pace++);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->player_p.x, data->player_p.y);
		data->player_p.y -= 64;
	}
}

void	render_down(t_mlx_data *data)
{
	int	new_pos_y;

	new_pos_y = (data->player_p.y) + 64;
	change_player(data, "./textures/player/down1.xpm");
	if (data->ground.grid[(new_pos_y) / 64][(data->player_p.x) / 64] != '1')
	{
		ft_printf("%d\n", data->count.pace++);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->player_p.x, data->player_p.y);
		data->player_p.y += 64;
	}
}

void	render_left(t_mlx_data *data)
{
	int	new_x;

	new_x = (data->player_p.x) - 64;
	change_player(data, "./textures/player/left1.xpm");
	if (data->ground.grid[(data->player_p.y) / 64][(new_x) / 64] != '1')
	{
		ft_printf("%d\n", data->count.pace++);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->player_p.x, data->player_p.y);
		data->player_p.x -= 64;
	}
}

void	render_right(t_mlx_data *data)
{
	int	new_x;

	new_x = (data->player_p.x) + 64;
	change_player(data, "./textures/player/right1.xpm");
	if (data->ground.grid[(data->player_p.y) / 64][(new_x) / 64] != '1')
	{
		ft_printf("%d\n", data->count.pace++);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->player_p.x, data->player_p.y);
		data->player_p.x += 64;
	}
}
