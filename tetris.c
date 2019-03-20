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
	int		x;
	int		y;
	char	found;
	int		anc_x;
	int		anc_y;

	y = 0;
	found = 0;
	while (y < 4)
	{
		x = 0;
		while (tetra[y][x] == '.')
			x++;
		if (tetra[y][x] == '#' && found == '0')
		{
			anc_x = x;
			anc_y = y;
			found = 1;
			x++;
		}
		if (found && tetra[y][x])
		{
			if (tetra[y][x] == '#' && found == '1')
			{
				tetramino->block1[0] = y - anc_y;
				tetramino->block1[1] = x - anc_x; //convert x,y according to anchors x & y
				found = '2';
			}
			else if (tetra[y][x] == '#' && found == '2')
			{
				tetramino->block2[0] = y - anc_y;
				tetramino->block2[1] = x - anc_x; //store x,y to int arr element of struct
				found = '3';
			}
			else if (tetra[y][x] == '#' && found == '3')
			{
				tetramino->block3[0] = y - anc_y;
				tetramino->block3[1] = x - anc_x; //create indication of last block found
				found = '4';
			}
		}
		if (found == '4')
			break ;
		y++;
	}
	tetramino->letter_id = tetra[4][0]; //set incrementation on each entrance
	return (tetramino);
}

t_tetra			*ft_newtetra(char **tetra, char letter_id)
{
	t_tetra	*tetramino;

	if (!(tetramino = (t_tetra *)malloc(sizeof(*tetramino))))
		return (NULL);
	else
	{
		if (!(tetramino->block1 = (int *)malloc(sizeof(int) * 3)))
			return (NULL);
		if (!(tetramino->block2 = (int *)malloc(sizeof(int) * 3)))
			return (NULL);
		if (!(tetramino->block3 = (int *)malloc(sizeof(int) * 3)))
			return (NULL);
		if (!(tetramino->letter_id = (char)malloc(sizeof(char) * 2)))
			return (NULL);
		convertit(tetramino, tetra);
		tetramino->letter_id = letter_id;
	}
	ft_putchar(tetramino->letter_id);
	tetramino->next = NULL;
	return (tetramino);
}

static int  	signit(char **coordinate)
{
	int 	out;
	int 	sign;

	sign = 1;
	if (**coordinate == '-')
	{
		*coordinate += 1;
		sign = -1;
	}
	out = sign * (int)(**coordinate - '0');
	*coordinate += 1;
	return (out);
}

static t_tetra  *delit(char *coordinates, char chr)
{
	t_tetra *del;

	del = (t_tetra *)malloc(sizeof(t_tetra));
	del->block1 = (int *)malloc(sizeof(int) * 2);
	del->block1[0] = signit(&coordinates);
	del->block1[1] = signit(&coordinates);
	del->block2 = (int *)malloc(sizeof(int) * 2);
	del->block2[0] = signit(&coordinates);
	del->block2[1] = signit(&coordinates);
	del->block3 = (int *)malloc(sizeof(int) * 2);
	del->block3[0] = signit(&coordinates);
	del->block3[1] = signit(&coordinates);
	del->letter_id = chr;
	del->next = NULL;
	return (del);
}
