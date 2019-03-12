ft_check (int fd)
{
	int 	i;
	int		b;
	int		err;
	char	*buf[22];

	err = 0;
	i = 0;
	b = read(fd, buf, 21);
	while (b > 0 && buf[i])
	{
		while (4x)
		{
			while ((i + 1) % 5 != 0)
			{
				if	(buf[i] != '#' || buf[i] != '.')
					err = 1;
				i++;
			}
			if (buf[i++] != '\n')
				err = 1;
			if (err)
				break ;
		}
	}
}
