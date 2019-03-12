/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:58:03 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/11 19:58:05 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_next_line(char *line, size_t n)
{
	int		i;
	size_t	len;

	if ((len = ft_strlen(line)) != 4)
	{
		if (n == 5 && len <= 1)
			if (ft_strchr("\n", *line))
				return (1);
		return (-1);
	}
	i = 0;
	while (i < len && n < 4)
	{
		if (line[i] != '#' || line[i] != '.')
			return (-1);
		i++;
	}
	if (i != 4)
		return (-1);
	return (1);
}