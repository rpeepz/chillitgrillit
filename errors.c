/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/28 19:02:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	ft_error(unsigned int err_num)
{
	char	*err_msgs[9];

	if (err_num == 69)
	{
		ft_putendl("usage: ./fillit ... <filename>");
		return (1);
	}
	if (!err_num)
		return (0);
	err_msgs[0] = ": get_next_line failed";
	err_msgs[1] = ": invalid file descriptor";
	err_msgs[2] = ": five line or more tetramino found";
	err_msgs[3] = ": forbidden char found";
	err_msgs[4] = ": malloc failed";
	err_msgs[5] = ": bad tetramino found";
	err_msgs[6] = ": they're after me lucky charms!";
	err_msgs[7] = ": ";
	err_msgs[8] = ": Too many tetras";
	ft_putstr("error");
	if (ERR_SW)
		ft_putstr(err_msgs[err_num - 1]);
	ft_putchar('\n');
	return (1);
}
