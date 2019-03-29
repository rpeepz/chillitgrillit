/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tet_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:10:19 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/28 19:02:52 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_afterline(char **s, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[0][len] != '\n' && s[0][len])
		len++;
	if (s[0][len] == '\n')
	{
		if (line)
		{
			free(*line);
			*line = NULL;
		}
		*line = ft_strsub(s[0], 0, len);
		tmp = ft_strdup(s[0] + len + 1);
		free(s[0]);
		s[0] = tmp;
	}
	else if (s[0][len] == '\0')
	{
		free(*line);
		*line = ft_strdup(s[0]);
		ft_strdel(&s[0]);
	}
	return (1);
}

int			get_tet_line(const int fd, char **line)
{
	static char		*str[1];
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				i;

	if (fd < 0 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	while (((i = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[i] = '\0';
		if (!str[0])
			str[0] = ft_strnew(0);
		tmp = ft_strjoin(str[0], buf);
		free(str[0]);
		str[0] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	else if (i == 0 && (!str[0] || !str[0][0]))
		return (0);
	return (ft_afterline(str, line));
}

t_tetra		*find_tetra(t_tetra *tetra_list, char id)
{
	while (tetra_list && tetra_list->letter_id != id)
		tetra_list = tetra_list->next;
	return (tetra_list);
}

void		free_tetras(t_tetra *tetra)
{
	t_tetra	*next;

	while (tetra)
	{
		next = tetra->next;
		free(tetra);
		tetra = next;
	}
}
