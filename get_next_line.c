/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:10:19 by rpapagna          #+#    #+#             */
/*   Updated: 2019/02/27 18:10:21 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_afterline(char *s, char **line, int fd, int i)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[len] != '\n' && s[len])
		len++;
	if (s[len] == '\n')
	{
		*line = ft_strsub(s, 0, len);
		tmp = ft_strdup(s + len + 1);
		free(s);
		s = tmp;
		if (s[0] == '\0')
			ft_strdel(&s);
	}
	else if (s[len] == '\0')
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s);
		ft_strdel(&s);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				i;

	if (fd < 0 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	while (((i = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[i] = '\0';
		if (!str)
			str = ft_strnew(0);
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	else if (i == 0 && (!str || !str[0]))
		return (0);
	return (ft_afterline(str, line, fd, i));
}
