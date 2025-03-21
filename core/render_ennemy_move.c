/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ennemy_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 01:37:19 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/21 16:51:42 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_enemy(t_mlx_data *data, char *new_image_path)
{
	if (data->enemy.image)
		mlx_destroy_image(data->mlx_ptr, data->enemy.image);
	data->enemy.image = mlx_xpm_file_to_image(data->mlx_ptr, new_image_path,
			&data->enemy.width, &data->enemy.height);
	if (!data->enemy.image)
		return ;
}

void	move_ennemy_x(t_mlx_data *data)
{
	int	x;
	int	x_2;

	x = (data->enemy_p.x) + 64;
	x_2 = (data->enemy_p.x) - 64;
	if (((data->player_p.x - data->enemy_p.x) > 0
			&& data->ground.grid[(data->enemy_p.y) / 64][(x) / 64] != '1')
		&& ((data->player_p.x - data->enemy_p.x) > 0
			&& data->ground.grid[(data->enemy_p.y) / 64][(x) / 64] != 'C'))
	{
		change_enemy(data, "./textures/ennemy/wolf_right.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->enemy_p.x, data->enemy_p.y);
		data->enemy_p.x += 64;
	}
	else if (((data->player_p.x - data->enemy_p.x) < 0
			&& data->ground.grid[(data->enemy_p.y) / 64][(x_2) / 64] != '1')
		&& ((data->player_p.x - data->enemy_p.x) < 0
			&& data->ground.grid[(data->enemy_p.y) / 64][(x_2) / 64] != 'C'))
	{
		change_enemy(data, "./textures/ennemy/wolf_left.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->enemy_p.x, data->enemy_p.y);
		data->enemy_p.x -= 64;
	}
}

void	move_ennemy_y(t_mlx_data *data)
{
	int	y;
	int	y_2;

	y = (data->enemy_p.y) + 64;
	y_2 = (data->enemy_p.y) - 64;
	if (((data->player_p.y - data->enemy_p.y) > 0 && data->ground.grid[(y)
				/ 64][(data->enemy_p.x) / 64] != '1') && ((data->player_p.y
				- data->enemy_p.y) > 0 && data->ground.grid[(y)
				/ 64][(data->enemy_p.x) / 64] != 'C'))
	{
		change_enemy(data, "./textures/ennemy/wolf_down.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->enemy_p.x, data->enemy_p.y);
		data->enemy_p.y += 64;
	}
	else if (((data->player_p.y - data->enemy_p.y) < 0
			&& data->ground.grid[(y_2) / 64][(data->enemy_p.x) / 64] != '1')
		&& ((data->player_p.y - data->enemy_p.y) < 0 && data->ground.grid[(y_2)
			/ 64][(data->enemy_p.x) / 64] != 'C'))
	{
		change_enemy(data, "./textures/ennemy/wolf_up.xpm");
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->floor.image,
			data->enemy_p.x, data->enemy_p.y);
		data->enemy_p.y -= 64;
	}
}

void	move_enemy(t_mlx_data *data)
{
	static int	move_counter = 0;

	move_counter++;
	if (move_counter >= 1000)
	{
		if (abs((data->player_p.x - data->enemy_p.x)) > abs(data->player_p.y
				- data->enemy_p.y))
			move_ennemy_x(data);
		else
			move_ennemy_y(data);
		move_counter = 0;
	}
}
