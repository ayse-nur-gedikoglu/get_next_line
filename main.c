#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("error");
		return(1);
	}
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}