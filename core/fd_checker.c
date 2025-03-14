/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:27:24 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/11 21:49:16 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	first_line_lenght(char *line)
{
	size_t	line_length;

	line_length = ft_strlen(line);
	if (line[line_length - 1] == '\n')
		line[line_length - 1] = '\0';
	return (ft_strlen(line));
}

void	t_close(t_mlx_data *data, int fd, char *line)
{
	free(line);
	close(fd);
	ft_exit(data, "Error: verrify maps!\n");
}

void	fd_checker(t_mlx_data *data, char *map)
{
	int		fd;
	char	*line;
	size_t	first_line_length;
	size_t	line_length;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_exit(data, "error opening file descriptor !\n");
	line = get_next_line(fd);
	if (line != NULL)
		first_line_length = first_line_lenght(line);
	while (line)
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';
		if (ft_strlen(line) != first_line_length)
			t_close(data, fd, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
