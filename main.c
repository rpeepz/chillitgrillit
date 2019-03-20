#include "fillit.h"

int     main(int argc, char **argv)
{
	int fd;
	int err_num;
	char *tetra[5];

	if (argc != 2)
		return (1);
	else
	{
		tetra[0] = NULL;
		tetra[1] = NULL;
		tetra[2] = NULL;
		tetra[3] = NULL;
		tetra[4] = NULL;
		fd = open(argv[1], O_RDONLY);
		while (!(err_num = checkit(fd, tetra)))
			;
//		free(*tetra);
		close(fd);
		if (err_num != -1)
			ERR_MAC(err_num);
	}
//	while (1)
//		err_num = 0;
	return (0);
}

unsigned char	ft_error(unsigned int err_num)
{
	char	*err_msgs[4];

	if (!err_num)
		return (0);
	err_msgs[0] = "";
	err_msgs[1] = ": invalid file descriptor";
	err_msgs[2] = ": invalid input format";
	err_msgs[3] = ": get_next_line failed";
	ft_putstr("error");
	if (ERR_SW)
		ft_putstr(err_msgs[err_num - 1]);
	ft_putchar('\n');
	return (1);
}
