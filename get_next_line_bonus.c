#include "get_next_line_bonus.h"

char    *read_line(int fd, char *line)
{
    ssize_t read_byte;
    char    *buffer;

    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    read_byte = 1;
    while (!(ft_strchr(line, '\n')) && read_byte > 0)
    {
        read_byte = read(fd, buffer, BUFFER_SIZE);
        if (read_byte == -1)
        {
            free (buffer);
            return (NULL);
        }
        buffer[read_byte] = '\0';
        line = ft_strjoin(line, buffer);
    }
    free (buffer);
    return (line);
}

char    *new_line(char *line)
{
    char    *str;
    int     i;
    int     j;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    if (!line[i])
    {
        free (line);
        return (NULL);
    }
    str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (line[i] != '\0') 
        str[j++]=line[i++];
    str[j] = '\0';
    free (line);
    return (str);    
}

char    *ft_get_next_line(char *line)
{
    int     i;
    char    *str;

    i = 0;
    if (!line[i])
        return (NULL);
    while (line[i] && line[i] != '\n')
        i++;
    str = (char *)malloc(i + 2);
    if (!str)
        return (NULL);
    i = 0;
    while (line [i] && line [i] != '\n')
    {
        str [i] = line[i];
        i++;
    }
    if (line [i] == '\n')
    {
        str[i] = line[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*get_next_line(int fd)
{
	static char			*line[1024];
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	line[fd] = ft_get_line(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	next_line = ft_get_next_line(line[fd]);
	line[fd] = new_line(line[fd]);
	return (next_line);
}