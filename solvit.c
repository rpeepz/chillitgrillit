#include "fillit.h"

static size_t	lenit(t_tetra *tetra_list)
{
	size_t	len;

	len = 0;
	while (tetra_list && ++len)
		tetra_list = tetra_list->next;
	return (len);
}

void	freeit(char ***amap, size_t sqsz)
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

void	freelit(t_tetra *tetra)
{
	if (tetra)
	{
		freelit(tetra->next);
		free(tetra->block1);
		free(tetra->block2);
		free(tetra->block3);
		//free((&tetra->letter_id));
	}
	free(tetra);
}

static char	*controlit(t_tetra *tetras)
{
	char	*chr_ids;
	size_t	c;

	c = lenit(tetras) + 1;
	IF_EXIT(!(chr_ids = (char *)malloc(sizeof(char) * c)), NULL);
	c = 0;
	while (tetras)
	{
		chr_ids[c] = tetras->letter_id;
		tetras = tetras->next;
		c++;
	}
	chr_ids[c] = '\0';
	return (chr_ids);
}

static int	technologic(char ***amap, t_tetra *tetras, size_t sqsz, char *chr_ids)
{
	char	**map;
	size_t	i;

	IF_EXIT(!chr_ids, -1); /*Error, Memory shortage*/
	map = NULL;
	if (!(*chr_ids))
		return (0); /*Success, No tetra remaining*/
	i = 0;
	while(chr_ids[i])
	{
		if (map)
			freeit(&map, sqsz);
		IF_EXIT(!(map = mapinit(sqsz, amap)), -1); /*Error, Memory shortage*/
		if (!fitit(&map, takeit(tetras, chr_ids[i]), sqsz))
		{
			if (!technologic(&map, tetras, sqsz, ft_strpop(chr_ids, i)))
			{
				free(chr_ids);
				freeit(amap, sqsz);
				*amap = map;
				return (0); /*Success, Path fits*/
			}
		}
		i++;
	}
	free(chr_ids);
	freeit(&map, sqsz);
	return (1); /*Failure, No paths left*/
}

int		solveit(t_tetra *tetra_list)
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
	//freelit(tetra_list);
	return (0);
}
