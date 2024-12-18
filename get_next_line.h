#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t    ft_strlen(char *str);
char    *ft_strchr(char *str, int c);

char    *read_line(int fd, char *line);
char	*get_next_line(int fd);

# endif