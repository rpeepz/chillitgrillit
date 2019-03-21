/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/19 17:55:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# define ERR_MAC(X) if(ft_error(X)) {return (1);}
# define ERR_SW 1
# define DEBUG 1
# define EMPTY_CHR '.'

# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tetra
{
	int				*block1;
	int				*block2;
	int				*block3;
	char			letter_id;
	struct s_tetra	*next;
}					t_tetra;
char				*strcnew(size_t len, char c);
static int			signit(char **coordinate);
static t_tetra		*delit(char *oordinates, char chr);
char				**mapinit(size_t sqsz);
int					fitit(char ***amap, t_tetra *tetromino,\
							size_t sqsz, char *order);
int					printit(char **map, size_t sqsz);
void				*convertit(t_tetra *tetromino, char **tetra);
void				tet_add(t_tetra **atet, t_tetra *new);
t_tetra				*tet_init(char **tetra, char letter_id);
t_tetra				*ft_newtetra(char **tetra, char letter_id);
unsigned char		ft_error(unsigned int err_num);
unsigned int		checkit(int fd, char **tetra);
int					get_next_line(const int fd, char **line);
int					ft_afterline(char **s, char **line);
unsigned int		check_next_line(char *line, size_t nline, size_t *apounds);

#endif
