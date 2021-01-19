//# include <sys/types.h>
//# include <sys/stat.h>
# include <fcntl.h>
#include "get_next_line.h"

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
	while (i++ < 12)
	{
		printf("return: %d\n", get_next_line(fd, &line));
		printf("line %d: %s\n\n**************************\n\n", i, line);
	}

	close(fd);
	return (0);
}
