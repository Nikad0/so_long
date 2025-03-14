/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_ball.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:55:16 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/04 18:15:58 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_fire_ball(t_mlx_data *data, char *new_image_path)
{
	if (data->fire_ball.image)
		mlx_destroy_image(data->mlx_ptr, data->fire_ball.image);
	data->fire_ball.image = mlx_xpm_file_to_image(data->mlx_ptr, new_image_path,
			&data->fire_ball.width, &data->fire_ball.height);
	if (!data->fire_ball.image)
		return ;
}

void	move_fire_ball_x(t_mlx_data *data)
{
	if ((data->player_p.x - data->fire_ball_p.x) > 0)
	{
		change_fire_ball(data, "./textures/fire_ball/fire_ball_right.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->fire_ball_p.x, data->fire_ball_p.y);
		data->fire_ball_p.x += 32;
	}
	else if ((data->player_p.x - data->fire_ball_p.x) < 0)
	{
		change_fire_ball(data, "./textures/fire_ball/fire_ball_left.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->fire_ball_p.x, data->fire_ball_p.y);
		data->fire_ball_p.x -= 32;
	}
}

void	move_fire_ball_y(t_mlx_data *data)
{
	if ((data->player_p.y - data->fire_ball_p.y) > 0)
	{
		change_fire_ball(data, "./textures/fire_ball/fire_ball_down.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->fire_ball_p.x, data->fire_ball_p.y);
		data->fire_ball_p.y += 32;
	}
	else if ((data->player_p.y - data->fire_ball_p.y) < 0)
	{
		change_fire_ball(data, "./textures/fire_ball/fire_ball_up.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->fire_ball_p.x, data->fire_ball_p.y);
		data->fire_ball_p.y -= 32;
	}
}

void	move_fire_ball(t_mlx_data *data)
{
	if ((((data->player_p.x == data->enemy_p.x))
			|| (data->player_p.y == data->enemy_p.y))
		&& data->count.fire_ball <= 0)
		data->count.fire_ball++;
	if (abs((data->player_p.x - data->fire_ball_p.x)) > abs(data->player_p.y
			- data->fire_ball_p.y))
		move_fire_ball_x(data);
	else
		move_fire_ball_y(data);
}
