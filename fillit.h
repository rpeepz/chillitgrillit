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
# define IF_EXIT(X, Y) if(X) {return (Y);}
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

void				initit(char **tetra, int *err_num,
						char *letter_id, t_tetra **tet_arr);
unsigned int		checkit(int fd, char **tetra);
unsigned char		ft_error(unsigned int err_num);
unsigned int		check_next_line(char *line, size_t nline, size_t *apounds);
void				*convertit(t_tetra *tetromino, char **tetra);
int					get_next_line(const int fd, char **line);
int					ft_afterline(char **s, char **line);
int					ft_newtetra(char **tetra, char letter_id, t_tetra **atet);
int					tet_append(t_tetra **head, t_tetra *new_tet);

t_tetra				*takeit(t_tetra *tetra_list, char id);
char				**mapinit(size_t sqsz, char ***amap);
int					fitit(char ***amap, t_tetra *tetra, size_t sqsz);
int					printit(char **map, size_t sqsz);
int					solveit(t_tetra *tetra_list);

#endif
