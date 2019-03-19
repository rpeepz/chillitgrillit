/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/18 22:53:20 by rpapagna         ###   ########.fr       */
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

typedef struct		s_tetra
{
	int				*block1;
	int				*block2;
	int				*block3;
	char			letter_id;
	struct s_tetra	*next;
}					t_tetra;

void 					*convertit(t_tetra *tetramino, char **tetra);
void					*ft_tetadd(t_tetra **tet_arr, t_tetra *new);
t_tetra				*ft_newtetra(char **tetra);
unsigned char		ft_error(unsigned int err_num);
unsigned int		checkit(int fd, char **tetra);
int					get_next_line(const int fd, char **line);
int					ft_afterline(char **s, char **line, int fd, int i);
unsigned int		check_next_line(char *line, size_t nline, size_t *apounds);

#endif
