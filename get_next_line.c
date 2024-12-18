#include "get_next_line.h"

char    *read_line(int fd, char *line)
{
    ssize_t read_byte;

    read_byte = 1;
    while (/* condition */)
    {
        /* code */
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