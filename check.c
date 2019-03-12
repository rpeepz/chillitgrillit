#include "libft.h"
#define ERR_MAC(X, Y) if(X) {free(Y); return (1);}

int		ft_check (int fd)
{
	int 	i;
	int		b;
	int		err;
	char	*buf[22];

	err = 0;
	i = 0;

/*	while ((b = read(fd, buf, 21)) > 0)
	{
		buf[b] == '\0';
		while ((i + 1) % 21 != 0)
		{
			while ((i + 1) % 5 != 0)
			{
				if	(buf[i] != '#' || buf[i] != '.')
				ERR_MAC (ft_strchr(buf, '#'), buf);
				i++;
			if (err)
				break ;
			}
			if (buf[i++] != '\n')
				err = 1;
		}
		if (!buf[i] || err)
			quit;
	}
*/
	return (0);
			ret = 0;
			while (ret < 4)
			{
				if (line[ret] != '#' || line[ret] != '.')
					return (-1);
				ret++;
			}
			if (line[ret] != '\n')
				return (-1);
}