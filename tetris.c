/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 23:43:40 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/19 17:53:46 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			*convertit(t_tetra *tetramino, char **tetra)
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
			anc[0] = i[0];
			anc[1] = i[1];
			found = 1;
			(i[1])++;
		}
		while (found && tetra[i[0]][i[1]])
		{
			if (tetra[i[0]][i[1]] == '#' && found == 1)
			{
				(tetramino->block1)[0] = i[0] - anc[0];
				(tetramino->block1)[1] = i[1] - anc[1]; //convert x,y according to anchors x & y
				found = 2;
			}
			else if (tetra[i[0]][i[1]] == '#' && found == 2)
			{
				(tetramino->block2)[0] = i[0] - anc[0];
				(tetramino->block2)[1] = i[1] - anc[1]; //store x,y to int arr element of struct
				found = 3;
			}
			else if (tetra[i[0]][i[1]] == '#' && found == 3)
			{
				(tetramino->block3)[0] = i[0] - anc[0];
				(tetramino->block3)[1] = i[1] - anc[1]; //create indication of last block found
				found = 4;
			}
			(i[1])++;
		}
		if (found == 4)
			break ;
		(i[0])++;
	}
	tetramino->letter_id = tetra[4][0]; //set incrementation on each entrance
	return (tetramino);
}

int			ft_newtetra(char **tetra, char letter_id, t_tetra **atet)
{
	t_tetra	*tetramino;

	IF_EXIT(!(tetramino = (t_tetra *)malloc(sizeof(*tetramino))), 0);
	IF_EXIT(!(tetramino->block1 = (int *)malloc(sizeof(int) * 2)), 0);
	IF_EXIT(!(tetramino->block2 = (int *)malloc(sizeof(int) * 2)), 0);
	IF_EXIT(!(tetramino->block3 = (int *)malloc(sizeof(int) * 2)), 0);
	IF_EXIT(!(tetramino->letter_id = (char)malloc(sizeof(char))), 0);
	convertit(tetramino, tetra);
	tetramino->letter_id = letter_id;
	tetramino->next = NULL;
	tet_append(atet, tetramino);
	return (1);
}

int			tet_append(t_tetra **head, t_tetra *new)
{
	t_tetra	*ETK;

	ETK = *head;
	if (!ETK)
		*head = new;
	else
	{
		while (ETK->next)
			ETK = ETK->next;
		ETK->next = new;
	}
	return (0);
}
