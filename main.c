#include "fillit.h"

int     main(int argc, char **argv)
{
	int fd;
	int ret;
	size_t count;
	char buff [22];
	char *line;

	if (argc != 2)
		return (-1);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 2)
		{
			count = 0;
			while((ret = get_next_line(fd, &line)) > 0)
			{
				if (count++ == 6)
					count = 1;
				if ((ret = check_next_line(line, count)) < 0)
					return (-1);
			}
		}
		close(fd);
	}
	return (0);
}