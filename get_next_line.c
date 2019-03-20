/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:10:19 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/14 16:42:52 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_next_line(const int fd, char **line)
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
int		ft_afterline(char **s, char **line)
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
			free (*line);
			*line = NULL;
		}
		*line = ft_strsub(s[0], 0, len);
		tmp = ft_strdup(s[0] + len + 1);
		free(s[0]);
		s[0] = NULL;
		s[0] = tmp;
		if (s[0] == '\0')
			ft_strdel(&s[0]);
	}
	else if (s[0][len] == '\0')
	{
		free (*line);
		*line = ft_strdup(s[0]);
		ft_strdel(&s[0]);
	}
	return (1);
}
