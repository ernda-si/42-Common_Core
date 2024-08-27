#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char *GNL(int fd)
{
	static char buffer[100];

	read (fd, buffer, 7);
	return(buffer);
}

int	main(void)
{
	int	fd = open ("test.txt", O_RDONLY);

	printf("%s\n", GNL(fd));
	// printf("%s\n", GNL(fd));
	close(fd);
}