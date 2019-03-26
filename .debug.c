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

int				loopalpha(int chr)
{
	if (chr == 'z')
		return ('A');
	if (chr == 'Z')
		return ('a');
	return (chr + 1);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		err_num;
	char	letter_id;
	char	*tetra[5];
	t_tetra	*tet_arr;

	IF_EXIT(argc != 2, ft_error(6));
	initit(tetra, &err_num, &letter_id, &tet_arr);
	fd = open(argv[1], O_RDONLY);
	while (!err_num)
	{
		err_num = checkit(fd, tetra);
		letter_id = loopalpha(letter_id);
		if (err_num <= 0)
			if (!(ft_newtetra(tetra, letter_id, &tet_arr)))
				return (ft_error(5));
	}
	close(fd);
	if (err_num != -1)
		if (ft_error(err_num))
			return (1);
	solveit(tet_arr);
	while (1)
		err_num = 1;
	return (0);
}

unsigned char	ft_error(unsigned int err_num)
{
	char	*err_msgs[7];

	if (err_num == 6)
	{
		ft_putendl("usage: ./fillit ... input file");
		return (1);
	}
	if (!err_num)
		return (0);
	err_msgs[0] = "";
	err_msgs[1] = ": invalid file descriptor";
	err_msgs[2] = ": invalid input format";
	err_msgs[3] = ": get_next_line failed";
	err_msgs[4] = ": malloc error";
	err_msgs[5] = ": they're after me lucky charms!";
	err_msgs[6] = ": bad tetramino found";
	ft_putstr("error");
	if (ERR_SW)
		ft_putstr(err_msgs[err_num - 1]);
	ft_putchar('\n');
	return (1);
}
