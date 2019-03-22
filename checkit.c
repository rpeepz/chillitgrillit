/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:41:40 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/18 22:41:44 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	checkit(int fd, char **tetra)
{
	size_t			nline;
	unsigned int	err_num;
	int				ret;
	size_t			pounds;

	if (fd < 3)
		return (2);
	nline = 0;
	pounds = 0;
	while (++nline < 6)
	{
		if ((ret = get_next_line(fd, &tetra[nline - 1])) < 0)
			break ;
		if ((err_num = check_next_line(tetra[nline - 1], nline, &pounds)) > 0)
			return (err_num);
		if (!ret)
			break;
	}
	if (ret == -1)
		return (4);
	if (pounds != 4)
		return (3);
	return (ret == 0 ? -1 : 0);
}

unsigned int	check_next_line(char *line, size_t nline, size_t *apounds)
{
	size_t	i;
	size_t	len;

	if ((len = ft_strlen(line)) != 4)
	{
		if (nline == 5 && len == 0)
			return (0);
		return (1);
	}
	i = 0;
	while (i < len && nline < 5)
	{
		if (line[i] == '#')
			(*apounds)++;
		else if (line[i] != '.')
			return (3);
		i++;
	}
	return (0);
}