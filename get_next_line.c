/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: agedikog <agedikog@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/12/27 17:29:20 by agedikog          #+#    #+#             */
/*   Updated: 2024/12/27 17:29:20 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char *buffer, char *line)
{
	if (line != NULL)
		free(line);
	free(buffer);
	return (NULL);
}

char	*read_buffered_line(int fd, char *line)
{
	ssize_t	read_byte;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(line, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (free_all(buffer, line));
		buffer[read_byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free_all(buffer, NULL));
	}
	free(buffer);
	return (line);
}

char	*new_line(char *line)
{
	char	*str;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(line) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*ft_get_next_line(char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (!line || !line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buffered_line(fd, line);
	if (!line || !*line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	next_line = ft_get_next_line(line);
	if (!next_line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = new_line(line);
	return (next_line);
}
