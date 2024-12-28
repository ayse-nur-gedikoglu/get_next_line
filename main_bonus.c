#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("test3.txt", O_RDONLY);
	if (fd < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("error");
		return(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
    while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
    while ((line = get_next_line(fd3)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
    close(fd2);
    close(fd3);
	return (0);
}