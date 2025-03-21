/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:23:27 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/21 17:05:15 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player(t_mlx_data *data, char *new_image_path)
{
	if (data->player.image)
		mlx_destroy_image(data->mlx_ptr, data->player.image);
	data->player.image = mlx_xpm_file_to_image(data->mlx_ptr, new_image_path,
			&data->player.width, &data->player.height);
	if (!data->player.image)
		return ;
}

void	draw_map(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->ground.grid[i])
	{
		while (data->ground.grid[i][j])
		{
			if (data->ground.grid[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->wall.image, j * 64, i * 64);
			}
			else if (data->ground.grid[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->floor.image, j * 64, i * 64);
			else if (data->ground.grid[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
					data->collectible.image, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_image(t_mlx_data *data)
{
	if (data->count.exit != 0)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->exit.image,
			data->exit_p.x, data->exit_p.y);
	if (data->count.enemy != 0)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->enemy.image,
			data->enemy_p.x, data->enemy_p.y);
	if (data->count.player != 0)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->player.image, data->player_p.x, data->player_p.y);
}

int	main_loop(t_mlx_data *data)
{
	move_enemy(data);
	draw_image(data);
	check_collision(data);
	collectible_count(data);
	return (0);
}
