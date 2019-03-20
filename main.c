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

int     main(int argc, char **argv)
{
	int		fd;
	int		err_num;
	size_t	sqsz;
	char	letter_id;
	char	*tetra[5];
	char	**map;
	t_tetra	*tet_arr;
	if (argc != 2)
		return (1);
	else
	{
		tetra[0] = NULL;
		tetra[1] = NULL;
		tetra[2] = NULL;
		tetra[3] = NULL;
		tetra[4] = NULL;
		letter_id = '@';
		fd = open(argv[1], O_RDONLY);
		while (!(err_num = checkit(fd, tetra)))
		{
			++letter_id;
			if (!tet_arr){
				if(!(tet_arr = ft_newtetra(tetra, letter_id)))
					return (ft_error(5));
			}
			//else
			//	tet_add(t_tetra **tet_arr, t_tetra *new)
		}
			//free(*tetra);
		close(fd);
//		ft_putchar(tetra[3][1]);
//		ft_putchar(tet_arr->letter_id);
//	printf("%c",tet_arr->letter_id); // test print
		if (err_num != -1)
			ERR_MAC(err_num);
	}
	//while (1)
	//err_num = 0;
	return (0);
}

unsigned char	ft_error(unsigned int err_num)
{
	char	*err_msgs[5];

	if (!err_num)
		return (0);
	err_msgs[0] = "";
	err_msgs[1] = ": invalid file descriptor";
	err_msgs[2] = ": invalid input format";
	err_msgs[3] = ": get_next_line failed";
	err_msgs[4] = ": malloc error"; //new error msg
	ft_putstr("error");
	if (ERR_SW)
		ft_putstr(err_msgs[err_num - 1]);
	ft_putchar('\n');
	return (1);
}
