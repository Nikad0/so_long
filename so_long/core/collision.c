/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:35:18 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/12 03:02:26 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_count(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->ground.grid[i])
	{
		while (data->ground.grid[i][j])
		{
			if (data->ground.grid[data->player_p.y / 64][data->player_p.x
				/ 64] == 'C')
			{
				data->count.collectible--;
				data->ground.grid[data->player_p.y / 64][data->player_p.x
					/ 64] = '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_collision(t_mlx_data *data)
{
	if (data->count.enemy != 0)
	{
		if (abs(data->player_p.x - data->enemy_p.x) < 64 && abs(data->player_p.y
				- data->enemy_p.y) < 64)
		{
			printf("Game Over! The enemy caught you!\n");
			destroy_data(data);
		}
	}
	if (abs(data->player_p.x - data->exit_p.x) <= 10 && abs(data->player_p.y
			- data->exit_p.y) <= 10 && data->exit_bool > 0)
	{
		printf("congratulation you won!\n");
		destroy_data(data);
	}
	if (data->count.collectible == 0)
		data->exit_bool += 1;
}
