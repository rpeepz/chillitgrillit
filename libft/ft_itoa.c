/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 00:13:27 by rpapagna          #+#    #+#             */
/*   Updated: 2019/02/20 00:13:27 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 0;
	if (n < 0)
	{
		tmp *= -1;
		len = 1;
	}
	len += ft_intlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
