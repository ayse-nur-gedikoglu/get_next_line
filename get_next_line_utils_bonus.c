/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <agedikog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:07:40 by agedikog          #+#    #+#             */
/*   Updated: 2024/12/27 21:08:33 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (str == NULL)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof(char) * 1);
		line[0] = '\0';
	}
	i = -1;
	while (line[++i])
		str[i] = line[i];
	j = 0;
	while (buffer[j])
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	free(line);
	return (str);
}
