/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/14 17:11:26 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# define ERR_MAC(X) if(ft_error(X)) {return (1);}
# define ERR_SW 1

# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

unsigned char	ft_error(unsigned int err_num);
unsigned int	check_next_tetra(int fd, char **tetra);
int				get_next_line(const int fd, char **line);
unsigned int	check_next_line(char *line, size_t nline, size_t *apounds);

#endif
