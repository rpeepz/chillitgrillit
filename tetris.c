/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 23:43:40 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/27 17:53:46 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		coordinateit(char **tetra, int anc[2], int i[2], t_tetra **t)
{
	char	found;

	found = 0;
	while (found < 3)
	{
		if (tetra[i[0]][i[1]] == '#' && found == 0)
		{
			((**t).block1)[0] = i[0] - anc[0];
			((**t).block1)[1] = i[1] - anc[1];
			found = 1;
		}
		else if (tetra[i[0]][i[1]] == '#' && found == 1)
		{
			((**t).block2)[0] = i[0] - anc[0];
			((**t).block2)[1] = i[1] - anc[1];
			found = 2;
		}
		else if (tetra[i[0]][i[1]] == '#' && found == 2)
		{
			((**t).block3)[0] = i[0] - anc[0];
			((**t).block3)[1] = i[1] - anc[1];
			break ;
		}
		incrementit(i);
	}
}

static void		anchorit(int *anchor, int *i)
{
	anchor[0] = i[0];
	anchor[1] = i[1];
	if (i[1] == 3)
	{
		i[1] = 0;
		(i[0])++;
	}
	else
		(i[1])++;
}

static void		*convertit(t_tetra *tetramino, char **tetra)
{
	int		i[2];
	int		anc[2];
	char	found;

	i[0] = 0;
	found = 0;
	while (i[0] < 4)
	{
		i[1] = 0;
		while (tetra[i[0]][i[1]] == '.')
			(i[1])++;
		if (tetra[i[0]][i[1]] == '#' && found == 0)
		{
			anchorit(anc, i);
			coordinateit(tetra, anc, i, &tetramino);
			break ;
		}
		(i[0])++;
	}
	return (tetramino);
}

static int		appendit(t_tetra **head, t_tetra *new)
{
	t_tetra	*etk;

	etk = *head;
	if (!etk)
		*head = new;
	else
	{
		while (etk->next)
			etk = etk->next;
		etk->next = new;
	}
	return (0);
}

int				combineit(char **tetra, char letter_id, t_tetra **atet)
{
	t_tetra	*tetramino;

	IF_EXIT(!(tetramino = (t_tetra *)malloc(sizeof(*tetramino))), 0);
	convertit(tetramino, tetra);
	tetramino->letter_id = letter_id;
	tetramino->next = NULL;
	appendit(atet, tetramino);
	return (1);
}
