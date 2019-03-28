/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/27 17:55:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# define IF_EXIT(X, Y) if(X) {return (Y);}
# define ERR_SW 0
# define DEBUG 0
# define EMPTY_CHR '.'

# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tetra
{
	int				block1[2];
	int				block2[2];
	int				block3[2];
	char			letter_id;
	struct s_tetra	*next;
}					t_tetra;
t_tetra				*find_tetra(t_tetra *tetra_list, char id);
char				**make_map(int sqsz, char ***amap);
int					ft_newtetra(char **tetra, char letter_id, t_tetra **atet);
int					tet_append(t_tetra **head, t_tetra *new_tet);
int					get_tet_line(const int fd, char **line);
int					show_dat_map(char **map, int sqsz);
int					solveit(t_tetra *tetrominos);
unsigned int		checkit(int fd, char **tetra);
int					fitit(char ***amap, t_tetra *tetra, int sqsz, int *imap);

#endif
