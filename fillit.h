/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:57:53 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/28 19:02:01 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define IF_EXIT(X, Y) if(X) {return (Y);}
# define ERR_SW 0
# define DEBUG 0
# define EMPTY_CHR '.'

# include "./libft/includes/libft.h"
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
unsigned char		ft_error(unsigned int err_num);
int					checkit(int fd, char **tetra);
int					combineit(char **tetra, char letter_id, t_tetra **atet);
int					countit(t_tetra *tetras);
void				incrementit(int i[2]);

int					solveit(t_tetra *tetrominos);
int					fitit(char ***amap, t_tetra *tetra, int sqsz, int *imap);
char				**map_makeit(int sqsz, char ***amap);
int					map_freeit(char ***amap, int sqsz);
void				tetra_freeit(t_tetra *tetra);
int					printit(char **map, int sqsz);

#endif
