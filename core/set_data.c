/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:20:27 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 20:21:23 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_exists(const char *path)
{
	return (access(path, F_OK) != -1);
}

void	set_content(t_mlx_data *data)
{
	data->content.wall = '1';
	data->content.space = '0';
	data->content.player = 'P';
	data->content.exit = 'E';
	data->content.collectible = 'C';
	data->content.enemy = 'B';
	data->count.player = 0;
	data->count.enemy = 0;
	data->count.exit = 0;
	data->count.collectible = 0;
	data->count.fire_ball = 0;
	data->exit_bool = 0;
}

void	set_data_path(t_mlx_data *data)
{
	data->enemy.path = "./textures/ennemy/wolf_down.xpm";
	if (!file_exists(data->enemy.path))
		ft_exit(data, "Error: Enemy texture file not found\n");
	data->floor.path = "./textures/map/sol.xpm";
	if (!file_exists(data->floor.path))
		ft_exit(data, "Error: floor texture file not found\n");
	data->player.path = "./textures/player/down1.xpm";
	if (!file_exists(data->player.path))
		ft_exit(data, "Error: player texture file not found\n");
	data->collectible.path = "./textures/map/collectible.xpm";
	if (!file_exists(data->collectible.path))
		ft_exit(data, "Error: collectible texture file not found\n");
	data->wall.path = "./textures/map/tree.xpm";
	if (!file_exists(data->wall.path))
		ft_exit(data, "Error: wall texture file not found\n");
	data->exit.path = "./textures/map/exit.xpm";
	if (!file_exists(data->exit.path))
		ft_exit(data, "Error: exit texture file not found\n");
	data->fire_ball.path = "./textures/utils/fire_ball_left.xpm";
	if (!file_exists(data->fire_ball.path))
		ft_exit(data, "Error: fire_ball_left texture file not found\n");
	data->count.pace = 1;
}

void	set_data_img(t_mlx_data *data)
{
	set_data_path(data);
	data->floor.image = mlx_xpm_file_to_image(data->mlx_ptr, data->floor.path,
			&data->floor.width, &data->floor.height);
	if (!data->floor.image)
		ft_exit(data, "error loading image !\n");
	data->player.image = mlx_xpm_file_to_image(data->mlx_ptr, data->player.path,
			&data->player.width, &data->player.height);
	if (!data->player.image)
		ft_exit(data, "error loading image !\n");
	data->collectible.image = mlx_xpm_file_to_image(data->mlx_ptr,
			data->collectible.path, &data->collectible.width,
			&data->collectible.height);
	if (!data->collectible.image)
		ft_exit(data, "error loading image !\n");
	data->wall.image = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.path,
			&data->wall.width, &data->wall.height);
	if (!data->wall.image)
		ft_exit(data, "error loading image !\n");
	data->exit.image = mlx_xpm_file_to_image(data->mlx_ptr, data->exit.path,
			&data->exit.width, &data->exit.height);
	if (!data->exit.image)
		ft_exit(data, "error loading image !\n");
	if (data->count.enemy != 0)
		data->enemy.image = mlx_xpm_file_to_image(data->mlx_ptr,
				data->enemy.path, &data->enemy.width, &data->enemy.height);
}
