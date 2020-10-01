#include <stdlib.h>
#include <stdio.h>

// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// read
#include <unistd.h>

#define BUFFER_SIZE 4096

char *set_line(char *buf, int start, int i)
{
	char *str;
	int y;

	str = malloc(sizeof(char) * (i - start) + 1);
	y = 0;
	while (start != i)
		str[y++] = buf[start++];
	str[y] = '\0';
	printf("str = %s\n", str);
	return (str);
}

int	find_new_line(char *buf, char **line, int i)
{
	int start;

	start = i;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	*line = NULL;
	*line = malloc(sizeof(char) * (i - start) + 1);
	*line = set_line(buf, start, i);
	if (buf[i + 1] && buf[i] == '\n')
	 i++;
	return (i);
}

int gnl(int fd, char **line)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	static	int	i = 0;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	
	i = find_new_line(buf, line, i);
	printf("%d\n", i);

	return (0);
}

int main(void)
{
	int				fd;
	char			*line;
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	
	line = NULL;

	fd = open("read.txt", O_RDONLY);
	//gnl(fd, &line);
	if (fd < 0)
		return (-1);
	
	gnl(fd, &line);
	printf("line: %s\n", line);
	gnl(fd, &line);
	printf("line: %s\n", line);
	gnl(fd, &line);
	gnl(fd, &line);
	gnl(fd, &line);
	gnl(fd, &line);
	gnl(fd, &line);
	gnl(fd, &line);

	close(fd);
	return (0);
}