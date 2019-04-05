/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:53:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/05 13:14:22 by rpapagna         ###   ########.fr       */
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

static int		loopit(int chr, int *err_num)
{
	if (chr == 'Z')
		*err_num = 8;
	return (chr + 1);
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
		if ((err_num = checkit(fd, tetra)) > 0)
			break ;
		if ((letter_id = loopit(letter_id, &err_num)) && err_num <= 0)
			if (!(combineit(tetra, letter_id, &tetrominos)))
				return (ft_error(5));
	}
	close(fd);
	IF_EXIT(((err_num != -1) && ft_error(err_num)), 1);
	solveit(tetrominos);
	tetra_freeit(tetrominos);
	line_freeit(tetra, 4);
	return (0);
}
