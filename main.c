#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int main(void)
{
	int				fd;
	char			*line;
	int				i;
	
	line = NULL;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (-1);

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("line %d: %s$\n", i, line);
		i++;
	}
	printf("line %d: %s$\n", i, line);
	close(fd);
	return (0);
}
