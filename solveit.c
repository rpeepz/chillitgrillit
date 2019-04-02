/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmbomeyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:20:69 by jmbomeyo          #+#    #+#             */
/*   Updated: 2019/03/28 19:12:40 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		free_map(char ***amap, int sqsz)
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

static int		how_many_tetras(t_tetra *tetras)
{
	int	len;

	len = 0;
	while (tetras && ++len)
		tetras = tetras->next;
	return (len);
}

static char		*getstr_ids(t_tetra *tetras)
{
	char	*char_ids;
	int		c;

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

static int		logic_loop(char ***amap, t_tetra *t, int sz, char *ids)
{
	char		**map;
	int			i;
	int			imap;
	static int	calls;

	if (!(map = NULL) && ++calls && !(*amap))
		calls = 0;
	if ((i = -1) && !(*ids))
	{
		free(ids);
		return (0);
	}
	while (ids[++i] && (imap = -1) && !(calls > 9000))
		while ((imap != sz * sz) && !(calls > 9000))
		{
			IF_EXIT((free_map(&map, sz) && !(map = make_map(sz, amap))), -1);
			if (!fitit(&map, find_tetra(t, ids[i]), sz, &imap))
				if (!logic_loop(&map, t, sz, ft_strpop(ids, (int)i)))
				{
					free(ids);
					IF_EXIT((free_map(amap, sz) && (*amap = map)), 0);
				}
		}
	free(ids);
	return ((free_map(&map, sz) ? 1 : -1));
}

int				solveit(t_tetra *tetras)
{
	int		sqsz;
	int		block_count;
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
