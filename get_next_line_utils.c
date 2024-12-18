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