/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:53:58 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 18:08:56 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	check_ber(char *str, const char *ber)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str) - 4;
	j = 0;
	while (str[i])
	{
		while (str[i + j] == ber[j])
		{
			j++;
			if (ber[j] == '\0')
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

void	flood_fill(t_mlx_data *data, size_t x, size_t y)
{
	if (x <= 0 || y <= 0 || x >= data->map_dup.cols || y >= data->map_dup.rows)
		return ;
	if (data->map_dup.grid[y][x] == '1')
		return ;
	if (data->map_dup.grid[y][x] == 'C')
		data->staff_count.collectible_s++;
	else if (data->map_dup.grid[y][x] == 'E')
		data->staff_count.exit_s++;
	data->map_dup.grid[y][x] = '1';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

size_t	wall_checker(t_mlx_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->ground.grid[i])
	{
		while (data->ground.grid[i][j])
		{
			if (data->ground.grid[i][j] != '1' && (i == 0 || j == 0
					|| i == data->ground.rows - 1 || j == data->ground.cols
					- 1))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	map_checker(t_mlx_data *data, char *map)
{
	size_t	wall_checker_result;
	size_t	ber;

	wall_checker_result = wall_checker(data);
	ber = check_ber(map, ".ber");
	if (ber != 0)
		ft_exit(data, "Error\nmap is not in .ber !\n");
	if (wall_checker_result != 0)
		ft_exit(data, "Error\nmap is not closed !\n");
	flood_fill(data, data->player_p.x / 64, data->player_p.y / 64);
	if (data->count.exit != 1 || data->count.player != 1)
		ft_exit(data, "Error\nmap need 1 exit or player !\n");
	if (data->count.exit != data->staff_count.exit_s)
		ft_exit(data, "Error\nexit can't be reached !\n");
	if (data->count.collectible != data->staff_count.collectible_s)
		ft_exit(data, "Error\nsome collectible can't be reached !\n");
	if (data->count.collectible < 1)
		ft_exit(data, "Error\nnot enough collectible !\n");
	if (data->ground.rows > 32 || data->ground.cols > 60)
		ft_exit(data, "Error\nmap is to big !\n");
}
