#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // for open
#include <unistd.h>

int main(void)
{
	int				fd;
	char			*line;
	int				i;
	
	line = NULL;

	fd = open("read.txt", O_RDONLY);
	if (fd < 0)
		return (-1);

	i = 0;
	while (i++ < 7)
	{
		printf("return: %d\n", get_next_line(fd, &line));
		printf("line: %s\n", line);
	}
	
	close(fd);
	return (0);
}
