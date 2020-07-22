#include <stdlib.h>
#include <stdio.h>

// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// read
#include <unistd.h>

#define BUFFER_SIZE 4096

int gnl(int fd, char **line)
{

}

int print_line(char buf[BUFFER_SIZE + 1], int i, int j)
{
	while (i != j)
	{
		printf("%c", buf[j]);
		j++;
	}
	return (j);
}

int main(void)
{
	int fd;
	int ret;
	char buf[BUFFER_SIZE + 1];
	int i;

	fd = open("read.txt", O_RDONLY);
	if (fd < 0)
		return (-1);

	while ((ret = read(fd, buf, BUFFER_SIZE)))
		buf[ret] = '\0';

	i = 0;
	int j = 0;

	while (buf[i] && buf[i - 1] != '\n')
		i++;
	j = print_line(buf, i, j);
	i++;

	while (buf[i] && buf[i - 1] != '\n')
		i++;
	print_line(buf, i, j);

	close(fd);
	return (0);
}