/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmbomeyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:20:69 by jmbomeyo          #+#    #+#             */
/*   Updated: 2019/03/19 21:58:44 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**mapinit(size_t sqsz)
{
	char	**map;
	size_t	i;

	if (!(map = (char **)(malloc(sizeof(char *) * sqsz))))
		return (NULL);
	i = -1;
	while (++i < sqsz)
		if (!(map[i] = ft_strcnew(sqsz, '.')))
			return (NULL);
	return (map);
}

static int		dropit(char ***amap, int sqsz, int b[4][2], char chr)
{
	char	**map;

	map = *amap;
	if (b[1][0] < sqsz && \
		b[2][0] < sqsz && \
		b[3][0] < sqsz && \
		0 <= b[1][1] && b[1][1] < sqsz && \
		0 <= b[2][1] && b[2][1] < sqsz && \
		0 <= b[3][1] && b[3][1] < sqsz && \
		map[b[0][0]][b[0][1]] == EMPTY_CHR && \
		map[b[1][0]][b[1][1]] == EMPTY_CHR && \
		map[b[2][0]][b[2][1]] == EMPTY_CHR && \
		map[b[3][0]][b[3][1]] == EMPTY_CHR)
	{
		map[b[0][0]][b[0][1]] = chr;
		map[b[1][0]][b[1][1]] = chr;
		map[b[2][0]][b[2][1]] = chr;
		map[b[3][0]][b[3][1]] = chr;
		return (1);
	}
	return (0);
}

static t_tetra	*takeit(t_tetra *tetra_list, char id)
{
	while (tetra_list && tetra_list->letter_id != id)
		tetra_list = tetra_list->next;
	return (tetra_list);
}

int				fitit(char ***amap, t_tetra *tet_arr, size_t sqsz, char *order)
{
	size_t	i;
	t_tetra	*tetra_falling;
	int		b[4][2];

	i = -1;
	tetra_falling = takeit(tet_arr, *order);
	while (++i < sqsz * sqsz)
	{
		b[0][0] = (int)(i / sqsz);
		b[0][1] = (int)(i % sqsz);
		b[1][0] = b[0][0] + (tetra_falling->block1)[0];
		b[1][1] = b[0][1] + (tetra_falling->block1)[1];
		b[2][0] = b[0][0] + (tetra_falling->block2)[0];
		b[2][1] = b[0][1] + (tetra_falling->block2)[1];
		b[3][0] = b[0][0] + (tetra_falling->block3)[0];
		b[3][1] = b[0][1] + (tetra_falling->block3)[1];
		if (dropit(amap, (int)sqsz, b, tetra_falling->letter_id))
			if (!(tetra_falling = takeit(tet_arr, *(++order))))
				return (0);
	}
	return (-1);
}

int				printit(char **map, size_t sqsz)
{
	size_t	i;

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
