#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_WRONLY);
	write(3, "oi", 3);
	close(fd);
}