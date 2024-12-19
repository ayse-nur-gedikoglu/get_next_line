#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t    ft_strlen(char *str);
char    *ft_strchr(char *str, int c);
char    *ft_strjoin(char *line, char *buffer);

char    *read_line(int fd, char *line);
char    *new_line(char *line);
char    *ft_get_next_line(char *line);
char	*get_next_line(int fd);

# endif