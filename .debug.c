/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:53:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/22 18:07:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#undef ERR_SW
#define ERR_SW 1
#undef DEBUG
#define DEBUG 1

static void		initit(char **tetra, int *err_num, \
						char *letter_id, t_tetra **tet_arr)
{
	*err_num = 0;
	tetra[0] = NULL;
	tetra[1] = NULL;
	tetra[2] = NULL;
	tetra[3] = NULL;
	tetra[4] = NULL;
	*letter_id = '@';
	*tet_arr = NULL;
}

static int		loopit(int chr)
{
	if (chr == 'z')
		return ('A');
	if (chr == 'Z')
		return ('a');
	return (chr + 1);
}

unsigned char	ft_error(unsigned int err_num)
{
	char	*err_msgs[9];

	if (err_num == 0)
	{
		ft_putendl("usage: ./fillit ... <filename>");
		return (1);
	}
	if (!err_num)
		return (0);
	err_msgs[0] = ": get_next_line failed";
	err_msgs[1] = ": invalid file descriptor";
	err_msgs[2] = ": five line or more tetramino found";
	err_msgs[3] = ": forbidden char found";
	err_msgs[4] = ": get_next_line failed";
	err_msgs[5] = ": bad tetramino found";
	err_msgs[6] = ": they're after me lucky charms!";
	err_msgs[7] = ": ";
	err_msgs[8] = ": Too many tetras";
	ft_putstr("error");
	if (ERR_SW)
		ft_putstr(err_msgs[err_num - 1]);
	ft_putchar('\n');
	return (1);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		err_num;
	char	letter_id;
	char	*tetra[5];
	t_tetra	*tetrominos;

	IF_EXIT(argc != 2, ft_error(6));
	initit(tetra, &err_num, &letter_id, &tetrominos);
	fd = open(argv[1], O_RDONLY);
	while (!err_num)
	{
		err_num = checkit(fd, tetra);
		letter_id = loopit(letter_id);
		if (err_num <= 0)
			if (!(combineit(tetra, letter_id, &tetrominos)))
				return (ft_error(5));
	}
	close(fd);
	if (err_num != -1)
		if (ft_error(err_num))
			return (1);
	solveit(tetrominos);
	IF_EXIT(system("leaks fillit"), 0);
}

int				printit(char **map, int sqsz)
{
	int		i;

	i = -1;
	while (++i < sqsz)
	{
		if (DEBUG)
		{
			ft_putchar('[');
			ft_putnbr(i);
			ft_putstr("] ");
		}
		ft_putstr(map[i]);
		if (DEBUG)
			ft_putchar('$');
		ft_putchar('\n');
	}
	return (0);
}
