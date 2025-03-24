/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:46:27 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/24 16:41:53 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_cols_rows(t_mlx_data *data, char *map)
{
	char	*line;
	int		fd;

	line = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(data, "erreur d' ouvertur fichier\n");
	line = get_next_line(fd);
	while (line)
	{
		data->map_dup.rows++;
		if (data->map_dup.cols == 0)
			data->map_dup.cols = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
	}
	if (data->map_dup.rows == 0 || data->map_dup.cols == 0)
	{
		ft_exit(data, "map vide !\n");
		destroy_data(data);
	}
	close(fd);
}

static void	grid_allocation(t_mlx_data *data)
{
	size_t	i;

	i = 0;
	data->map_dup.grid = malloc((data->map_dup.rows + 1) * sizeof(char *));
	if (data->map_dup.grid == NULL)
		ft_exit(data, "Erreur d'allocation mémoire pour les lignes.\n");
	while (i < data->map_dup.rows)
	{
		data->map_dup.grid[i] = malloc((data->map_dup.cols + 1) * sizeof(char));
		if (data->map_dup.grid[i] == NULL)
		{
			free_tab(data);
			ft_exit(data, "Erreur d'allocation mémoire pour la ligne\n");
		}
		i++;
	}
	data->map_dup.grid[data->map_dup.rows] = NULL;
}

static void	grid_filling(t_mlx_data *data, char *map)
{
	size_t	i;
	size_t	j;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(data, "Erreur d'ouverture du fichier\n");
	line = get_next_line(fd);
	while (line && i < data->map_dup.rows)
	{
		j = 0;
		while (j < data->map_dup.cols)
		{
			data->map_dup.grid[i][j] = line[j];
			j++;
		}
		data->map_dup.grid[i][data->map_dup.cols] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	map_dup_init(char *map, t_mlx_data *data)
{
	data->map_dup.rows = 0;
	data->map_dup.cols = 0;
	data->map_dup.grid = NULL;
	get_cols_rows(data, map);
	grid_allocation(data);
	grid_filling(data, map);
	return (0);
}
