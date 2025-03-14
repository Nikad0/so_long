/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:31:11 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/11 21:51:40 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	size_t	i;
	char	tmp;

	i = 0;
	tmp = (unsigned char)c;
	while (s[i] && s[i] != tmp)
		i++;
	if (s[i] == tmp)
		return (i + 1);
	return (0);
}
