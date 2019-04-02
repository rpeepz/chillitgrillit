/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:53:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/28 19:07:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static int		loopalpha(int chr, int *err_num, int fd)
{
	if (chr == 'Z')
	{
		close(fd);
		*err_num = 8;
	}
	return (chr + 1);
}

unsigned char	ft_error(unsigned int err_num)
{
	char	*err_msgs[9];

	if (err_num == 69)
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
	err_msgs[4] = ": malloc failed";
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

	IF_EXIT(argc != 2, ft_error(69));
	initit(tetra, &err_num, &letter_id, &tetrominos);
	fd = open(argv[1], O_RDONLY);
	while (!err_num)
	{
		err_num = checkit(fd, tetra);
		if ((letter_id = loopalpha(letter_id, &err_num, fd)) && err_num <= 0)
			if (!(ft_newtetra(tetra, letter_id, &tetrominos)))
				return (ft_error(5));
	}
	close(fd);
	fd = 0;
	while (fd < 5)
		free(tetra[fd++]);
	IF_EXIT(((err_num != -1) && ft_error(err_num)), 1);
	solveit(tetrominos);
	free_tetras(tetrominos);
	return (0);
}

int				show_dat_map(char **map, int sqsz)
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
