/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:47:38 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/28 13:25:48 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(t_mlx_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (data->ground.grid)
	{
		while (data->ground.grid[i])
		{
			free(data->ground.grid[i]);
			i++;
		}
		free(data->ground.grid);
	}
	data->ground.grid = NULL;
	if (data->map_dup.grid)
	{
		while (data->map_dup.grid[j])
		{
			free(data->map_dup.grid[j]);
			j++;
		}
		free(data->map_dup.grid);
	}
	data->map_dup.grid = NULL;
}

void	destroy_data(t_mlx_data *data)
{
	if (data->player.image)
		mlx_destroy_image(data->mlx_ptr, data->player.image);
	if (data->floor.image)
		mlx_destroy_image(data->mlx_ptr, data->floor.image);
	if (data->enemy.image)
		mlx_destroy_image(data->mlx_ptr, data->enemy.image);
	if (data->collectible.image)
		mlx_destroy_image(data->mlx_ptr, data->collectible.image);
	if (data->wall.image)
		mlx_destroy_image(data->mlx_ptr, data->wall.image);
	if (data->exit.image)
		mlx_destroy_image(data->mlx_ptr, data->exit.image);
	if (data->fire_ball.image)
		mlx_destroy_image(data->mlx_ptr, data->fire_ball.image);
	free_tab(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	ft_exit(t_mlx_data *data, char *msg)
{
	if (msg)
		while (*msg)
			write(2, msg++, 1);
	destroy_data(data);
	exit(-1);
}



int	main(int ac, char **av)
{
	t_mlx_data	data;

	ft_memset(&data, 0, sizeof(t_mlx_data));
	if (ac != 2)
		ft_exit(&data, "NO_FILE\n");
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_exit(&data, "error mlx\n");
	fd_checker(&data, av[1]);
	map_init(av[1], &data);
	map_dup_init(av[1], &data);
	map_checker(&data, av[1]);
	if (!data.mlx_ptr)
		return (1);
	set_data_img(&data);
	data.mlx_win = mlx_new_window(data.mlx_ptr, (data.ground.cols * 64),
			(data.ground.rows * 64), "so_long");
	if (!data.mlx_win)
		return (destroy_data(&data), (0));
	draw_map(&data);
	mlx_hook(data.mlx_win, 02, 1L << 0, (void *)input_action, &data);
	mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_hook(data.mlx_win, 17, 0, (void *)destroy_data, &data);
	mlx_loop_hook(data.mlx_ptr, (void *)main_loop, &data);
	mlx_loop(data.mlx_ptr);
}
