/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:53:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/19 18:56:23 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (letter_id == 'Z')
			letter_id = '`';
		++letter_id;
		if (err_num <= 0)
			if (!(ft_newtetra(tetra, letter_id, &tet_arr)))
				return (ft_error(5));
	}
	close(fd);
	if (err_num != -1)
		if (ft_error(err_num))
			return (1);
	solveit(tet_arr);
	return (0);
}

unsigned char	ft_error(unsigned int err_num)
{
	char	*err_msgs[5];

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
	ft_putstr("error");
	if (ERR_SW)
		ft_putstr(err_msgs[err_num - 1]);
	ft_putchar('\n');
	return (1);
}
