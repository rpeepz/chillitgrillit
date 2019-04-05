/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmbomeyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:20:69 by jmbomeyo          #+#    #+#             */
/*   Updated: 2019/04/05 03:09:37 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*id_stringit(t_tetra *tetras)
{
	char	*char_ids;
	int		c;

	c = countit(tetras) + 1;
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

static t_tetra	*findit(t_tetra *tetra_list, char id)
{
	while (tetra_list && tetra_list->letter_id != id)
		tetra_list = tetra_list->next;
	return (tetra_list);
}

void			tetra_freeit(t_tetra *tetra)
{
	t_tetra	*next;

	while (tetra)
	{
		next = tetra->next;
		free(tetra);
		tetra = next;
	}
}

static int		technologic(char ***amap, t_tetra *t, int sz, char *ids)
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
	while (ids[++i] && (imap = -1) && !(calls > 90000))
		while ((imap != sz * sz) && !(calls > 90000))
		{
			IF_EXIT((map_freeit(&map, sz) && !(map = makeit(sz, amap))), -1);
			if (!fitit(&map, findit(t, ids[i]), sz, &imap))
				if (!technologic(&map, t, sz, ft_strpop(ids, (int)i)))
				{
					free(ids);
					IF_EXIT((map_freeit(amap, sz) && (*amap = map)), 0);
				}
		}
	free(ids);
	return ((map_freeit(&map, sz) ? 1 : -1));
}

int				solveit(t_tetra *tetras)
{
	int		sqsz;
	int		block_count;
	char	**map;

	block_count = 4 * countit(tetras);
	sqsz = 2;
	while (sqsz * sqsz < block_count)
		sqsz++;
	map = NULL;
	while (technologic(&map, tetras, sqsz, id_stringit(tetras)))
		sqsz++;
	printit(map, sqsz);
	map_freeit(&map, sqsz);
	return (0);
}
