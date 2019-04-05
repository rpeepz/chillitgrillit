/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/28 19:02:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	incrementit(int i[2])
{
	if (i[1] == 3)
	{
		i[1] = 0;
		(i[0])++;
	}
	else
		(i[1])++;
}

int		countit(t_tetra *tetras)
{
	int	len;

	len = 0;
	while (tetras && ++len)
		tetras = tetras->next;
	return (len);
}
