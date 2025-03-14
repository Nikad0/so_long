/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:25:57 by erbuffet          #+#    #+#             */
/*   Updated: 2025/01/08 14:47:34 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (!buffer[0])
		{
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
			{
				if (line != NULL && bytesread != -1)
					return (line);
				return (free(line), NULL);
			}
			buffer[bytesread] = '\0';
		}
		line = ft_strjoin(line, buffer);
		if (line && ft_strchr(buffer, '\n') != 0)
			return (ft_strcpy(buffer, buffer + ft_strchr(buffer, '\n')), line);
		buffer[0] = '\0';
	}
}
