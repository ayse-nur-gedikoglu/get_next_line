#include "get_next_line.h"

//read until end of file or \n
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
        
    }
       return(line);
}

char	*get_next_line(int fd)
{
    static char     *line;
    char            *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = ft_read_line(fd, line);
    if (!line)
        return (NULL);
}