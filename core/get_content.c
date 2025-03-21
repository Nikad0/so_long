/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:55:22 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/21 16:51:13 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_content(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->ground.grid[i])
	{
		while (data->ground.grid[i][j])
		{
			if (data->ground.grid[i][j] != '1' && data->ground.grid[i][j] != '0'
				&& data->ground.grid[i][j] != 'P'
				&& data->ground.grid[i][j] != 'C'
				&& data->ground.grid[i][j] != 'E'
				&& data->ground.grid[i][j] != 'B')
				ft_exit(data, "Error ! non-conform character in map !\n");
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_player(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->ground.grid[i])
	{
		while (data->ground.grid[i][j])
		{
			if (data->ground.grid[i][j] == 'P')
			{
				data->player_p.x += j * 64;
				data->player_p.y += i * 64;
				data->count.player += 1;
				data->ground.grid[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_enemy(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->ground.grid[i])
	{
		while (data->ground.grid[i][j])
		{
			if (data->ground.grid[i][j] == 'B')
			{
				data->enemy_p.x += j * 64;
				data->enemy_p.y += i * 64;
				data->count.enemy += 1;
				if (data->count.enemy != 1)
					ft_exit(data, "Error ! to many ennemy\n");
				data->ground.grid[i][j] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_exit(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->ground.grid[i])
	{
		while (data->ground.grid[i][j])
		{
			if (data->ground.grid[i][j] == 'E')
			{
				data->exit_p.x += j * 64;
				data->exit_p.y += i * 64;
				data->count.exit += 1;
				data->ground.grid[i][j] = '0';
			}
			if (data->ground.grid[i][j] == 'C')
				data->count.collectible++;
			j++;
		}
		j = 0;
		i++;
	}
}
