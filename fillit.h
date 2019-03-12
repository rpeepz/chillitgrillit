/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/11 19:57:55 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# define ERR_MAC(X, Y) if(X) {free(Y); return (1);}

# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);
int     check_next_line(char *line, size_t n);

#endif