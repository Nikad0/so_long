/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:40:41 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/11 21:09:59 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && *s2 && *s2 != '\n')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	if (s2 && *s2 == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (free(s1), dest);
}
