/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/28 19:02:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**map_makeit(int sqsz, char ***amap)
{
	char	**map;
	int		i;

	IF_EXIT(!(map = (char **)(malloc(sizeof(char *) * sqsz))), NULL);
	i = -1;
	while (++i < sqsz)
	{
		if (*amap)
			map[i] = ft_strdup((*amap)[i]);
		else
			map[i] = ft_strcnew(sqsz, '.');
		IF_EXIT(!map[i], NULL);
	}
	return (map);
}

int			map_freeit(char ***amap, int sqsz)
{
	int	i;

	if (*amap)
	{
		i = 0;
		while (i < sqsz)
		{
			free((*amap)[i]);
			i++;
		}
		free(*amap);
		*amap = NULL;
	}
	return (1);
}

static int	dropit(char ***amap, int sqsz, int b[4][2], char chr)
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

int			fitit(char ***amap, t_tetra *tetra, int sqsz, int *imap)
{
	int			block[4][2];

	while (++(*imap) < sqsz * sqsz)
	{
		block[0][0] = *imap / sqsz;
		block[0][1] = *imap % sqsz;
		block[1][0] = block[0][0] + (tetra->block1)[0];
		block[1][1] = block[0][1] + (tetra->block1)[1];
		block[2][0] = block[0][0] + (tetra->block2)[0];
		block[2][1] = block[0][1] + (tetra->block2)[1];
		block[3][0] = block[0][0] + (tetra->block3)[0];
		block[3][1] = block[0][1] + (tetra->block3)[1];
		if (dropit(amap, (int)sqsz, block, tetra->letter_id))
			return (0);
	}
	return (-1);
}

int			printit(char **map, int sqsz)
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
