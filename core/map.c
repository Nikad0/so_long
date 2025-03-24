/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:09:24 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 17:47:37 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_cols_rows(t_mlx_data *data, char *map)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(data, "erreur d' ouverture fichier\n");
	line = get_next_line(fd);
	while (line)
	{
		data->ground.rows++;
		if (data->ground.cols == 0)
			data->ground.cols = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
	}
	if (data->ground.rows == 0 || data->ground.cols == 0)
		ft_exit(data, "map vide !\n");
	close(fd);
}

static void	grid_allocation(t_mlx_data *data)
{
	size_t	i;

	i = 0;
	data->ground.grid = malloc((data->ground.rows + 1) * sizeof(char *));
	if (data->ground.grid == NULL)
		ft_exit(data, "Erreur d'allocation mémoire pour les lignes.\n");
	while (i < data->ground.rows)
	{
		data->ground.grid[i] = malloc((data->ground.cols + 1) * sizeof(char));
		if (data->ground.grid[i] == NULL)
		{
			free_tab(data);
			ft_exit(data, "Erreur d'allocation mémoire pour la ligne\n");
		}
		i++;
	}
	data->ground.grid[data->ground.rows] = NULL;
}

static void	grid_filling(t_mlx_data *data, char *map)
{
	char	*line;
	int		fd;
	size_t	i;
	size_t	j;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(data, "Erreur d'ouverture du fichier1\n");
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (j < ft_strlen(line) && j < data->ground.cols)
		{
			data->ground.grid[i][j] = line[j];
			j++;
		}
		data->ground.grid[i][j] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	map_init(char *map, t_mlx_data *data)
{
	data->ground.rows = 0;
	data->ground.cols = 0;
	data->ground.grid = NULL;
	get_cols_rows(data, map);
	grid_allocation(data);
	grid_filling(data, map);
	check_content(data);
	get_player(data);
	get_enemy(data);
	get_exit(data);
	return (0);
}
