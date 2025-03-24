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
	printf("%d: %s", fd, buffer);
	return(buffer);
}

int	main(void)
{
	int	fd = open ("bonus1", O_RDONLY);
	int	fd2 = open ("bonus2", O_RDONLY);
	int	fd3 = open ("bonus3", O_RDONLY);

	printf("fd: %s", GNL(fd));
	printf("fd2: %s", GNL(fd2));
	printf("fd3: %s", GNL(fd3));
	printf("fd: %s", GNL(fd));
	printf("fd2: %s", GNL(fd2));
	printf("fd3: %s", GNL(fd3));
	close(fd);
}