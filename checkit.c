/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:41:40 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/27 22:41:44 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		neighborhood_watch(char **the_hood)
{
	int		i;
	int		j;
	int		neighbors;

	neighbors = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (the_hood[i][j] == '#' && the_hood[i][j + 1] == '#')
				neighbors += 2;
			if (the_hood[i][j] == '#' && the_hood[i + 1][j] == '#')
				neighbors += 2;
			j++;
		}
		i++;
	}
	return (neighbors);
}

unsigned int	tet_next_line(char *line, size_t nline, size_t *apounds)
{
	size_t	i;
	size_t	len;

	if ((len = ft_strlen(line)) != 4)
	{
		if (nline == 5 && len == 0)
			return (0);
		return (3);
	}
	i = 0;
	while (i < len && nline < 5)
	{
		if (line[i] == '#')
			(*apounds)++;
		else if (line[i] != EMPTY_CHR)
			return (4);
		i++;
	}
	return (0);
}

unsigned int	checkit(int fd, char **tetra)
{
	size_t			n;
	size_t			pounds;
	unsigned int	err_num;
	int				reet;
	int				neighbors;

	if (fd < 0)
		return (2);
	n = 0;
	pounds = 0;
	while (++n < 6)
	{
		if ((reet = get_tet_line(fd, &tetra[n - 1])) <= 0)
			break ;
		if ((err_num = tet_next_line(tetra[n - 1], n, &pounds)) > 0)
			return (err_num);
	}
	if (reet == -1)
		return (1);
	if (pounds != 4)
		return (4);
	if ((neighbors = neighborhood_watch(tetra)) < 6)
		return (6);
	return (reet == 0 ? -1 : 0);
}

int				tet_append(t_tetra **head, t_tetra *new)
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

char			**make_map(int sqsz, char ***amap)
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
