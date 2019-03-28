/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:12:39 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/27 18:12:40 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_map(char ***amap, size_t sqsz)
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

static size_t	how_many_tetras(t_tetra *tetras)
{
	size_t	len;

	len = 0;
	while (tetras && ++len)
		tetras = tetras->next;
	return (len);
}

static char		*getstr_ids(t_tetra *tetras)
{
	char	*char_ids;
	size_t	c;

	c = how_many_tetras(tetras) + 1;
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

static int		logic_loop(char ***amap, t_tetra *t, size_t sqsz, char *ids)
{
	char	**map;
	int		i;

	if ((i = -1) && !(*ids))
		free(ids);
	IF_EXIT(!(map = NULL) && !(*ids), 0);
	while (ids[++i])
	{
		if (map)
			free_map(&map, sqsz);
		IF_EXIT(!(map = make_map(sqsz, amap)), -1);
		if (!fitit(&map, find_tetra(t, ids[i]), sqsz)) //work around these
			if (!logic_loop(&map, t, sqsz, ft_strpop(ids, (size_t)i))) //work around these
			{
				free(ids);
				free_map(amap, sqsz);
				*amap = map;
				return (0);
			}
	}
	free(ids);
	free_map(&map, sqsz);
	return (1);
}

int				solveit(t_tetra *tetras)
{
	size_t	sqsz;
	size_t	block_count;
	char	**map;

	block_count = 4 * how_many_tetras(tetras);
	sqsz = 2;
	while (sqsz * sqsz < block_count)
		sqsz++;
	map = NULL;
	while (logic_loop(&map, tetras, sqsz, getstr_ids(tetras)))
		sqsz++;
	show_dat_map(map, sqsz);
	free_map(&map, sqsz);
	return (0);
}
