#include "get_next_line.h"

size_t    ft_strlen(char *str)
{
    size_t i;

    i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strchr(char *str, int c)
{
    int i;

    if (!str)
        return (NULL);
    i = 0;
    if (c == '\0')
        return (&str[i]);
    while (str[i] != '\0')
    {
        if (str[i] == (char)c )
            return (&str[i]);
        i++;
    }
}

char    *ft_strjoin(char *line, char *buffer)
{
    size_t  i;
    size_t  j;
    char    *str;

    if (!line)
    {
        line = (char *)malloc(sizeof(char) * 1);
        line [0] = '\0';
    }
    if (!line || !buffer)
        return(NULL);
    str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
    if (!str)
        return(NULL);
    i = 0;
    while (line [i] != '\0')
    {
        str[i] = line [i];
        i++;
    } 
    j = 0;
    while (buffer[j] != '\0')
        str[i++] = buffer[j++];
    str[i] = '\0';
    free (line);
    return (str);
}
