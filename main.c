#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>  //for open
//#include "get_next_line.c"

int	get_next_line (int fd, char **line);

int main(int argc, char const *argv[])
{
	int fd;
	char	*line;

	
	fd = open("text.txt", O_RDONLY);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);
	return (0);
}
