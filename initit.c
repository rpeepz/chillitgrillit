/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:58:15 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/22 16:58:16 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initit(char **tetra, int *err_num, char *letter_id, t_tetra **tet_arr)
{
	*err_num = 0;
	tetra[0] = NULL;
	tetra[1] = NULL;
	tetra[2] = NULL;
	tetra[3] = NULL;
	tetra[4] = NULL;
	*letter_id = '@';
	*tet_arr = NULL;
}
