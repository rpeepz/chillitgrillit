/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:41:40 by rpapagna          #+#    #+#             */
/*   Updated: 2019/04/05 13:17:07 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		watchit(char **the_hood)
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
			if (i < 3 && (the_hood[i][j] == '#' && the_hood[i + 1][j] == '#'))
				neighbors += 2;
			j++;
		}
		i++;
	}
	return (neighbors);
}

void			line_freeit(char **tetra, int len)
{
	int		nline;

	nline = 0;
	while (nline < len && tetra[nline])
		free(tetra[nline++]);
}

unsigned int	validateit(char *line, size_t nline, size_t *apounds)
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

int				checkit(int fd, char **tetra)
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
	line_freeit(tetra, 5);
	while (++n < 6)
	{
		if ((reet = get_next_line(fd, &tetra[n - 1])) <= 0)
			break ;
		if ((err_num = validateit(tetra[n - 1], n, &pounds)) > 0)
			return (err_num);
	}
	if (reet == -1)
		return (1);
	if (pounds != 4)
		return (4);
	if ((neighbors = watchit(tetra)) < 6)
		return (6);
	return (reet == 0 ? -1 : 0);
}
