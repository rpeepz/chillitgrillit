/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmbomeyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:20:69 by jmbomeyo          #+#    #+#             */
/*   Updated: 2019/03/21 18:00:44 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	lenit(t_tetra *tetra_list)
{
	size_t	len;

	len = 0;
	while (tetra_list && ++len)
		tetra_list = tetra_list->next;
	return (len);
}

void			freeit(char ***amap, size_t sqsz)
{
	size_t	i;

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
}

static char		*controlit(t_tetra *tetras)
{
	char	*char_ids;
	size_t	c;

	c = lenit(tetras) + 1;
	IF_EXIT(!(char_ids = (char *)malloc(sizeof(char) * c)), NULL);
	c = 0;
	while (tetras)
	{
		char_ids[c] = tetras->letter_id;
		tetras = tetras->next;
		c++;
	}
	char_ids[c] = '\0';
	return (char_ids);
}

static int		technologic(char ***amap, t_tetra *t, size_t sqsz, char *ids)
{
	char	**map;
	int		i;

	if ((i = -1) && !(*ids))
		free(ids);
	IF_EXIT(!(map = NULL) && !(*ids), 0);
	while (ids[++i])
	{
		if (map)
			freeit(&map, sqsz);
		IF_EXIT(!(map = mapinit(sqsz, amap)), -1);
		printit(map, sqsz); //remove
		ft_putchar('\n');   //remove
		if (!fitit(&map, takeit(t, ids[i]), sqsz))
			if (!technologic(&map, t, sqsz, ft_strpop(ids, (size_t)i)))
			{
				free(ids);
				freeit(amap, sqsz);
				*amap = map;
				return (0);
			}
	}
	free(ids);
	freeit(&map, sqsz);
	return (1);
}

int				solveit(t_tetra *tetra_list)
{
	size_t	i;
	size_t	block_count;
	char	**map;

	block_count = 4 * lenit(tetra_list);
	i = 2;
	while (i * i < block_count)
		i++;
	map = NULL;
	while (technologic(&map, tetra_list, i, controlit(tetra_list)))
		i++;
	printit(map, i);
	freeit(&map, i);
	return (0);
}
