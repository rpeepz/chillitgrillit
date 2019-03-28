/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmbomeyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:20:69 by jmbomeyo          #+#    #+#             */
/*   Updated: 2019/03/27 19:00:44 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

t_tetra		*takeit(t_tetra *tetra_list, char id)
{
	while (tetra_list && tetra_list->letter_id != id)
		tetra_list = tetra_list->next;
	return (tetra_list);
}

int			fitit(char ***amap, t_tetra *tetra, size_t sqsz)
{
	size_t	i;
	int		b[4][2];

	i = -1;
	while (++i < sqsz * sqsz)
	{
		b[0][0] = (int)(i / sqsz);
		b[0][1] = (int)(i % sqsz);
		b[1][0] = b[0][0] + (tetra->block1)[0];
		b[1][1] = b[0][1] + (tetra->block1)[1];
		b[2][0] = b[0][0] + (tetra->block2)[0];
		b[2][1] = b[0][1] + (tetra->block2)[1];
		b[3][0] = b[0][0] + (tetra->block3)[0];
		b[3][1] = b[0][1] + (tetra->block3)[1];
		if (dropit(amap, (int)sqsz, b, tetra->letter_id))
			return (0);
	}
	return (-1);
}
