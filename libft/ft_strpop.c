/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 22:53:26 by rpapagna          #+#    #+#             */
/*   Updated: 2019/03/19 18:56:23 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpop(char *str, size_t id)
{
	size_t	len;
	size_t	i;
	char	*popped;

	len = ft_strlen(str);
	if (id < len && (popped = (char *)malloc(len * sizeof(char))))
	{
		i = -1;
		while (++i < id)
			popped[i] = str[i];
		while (++i <= len)
			popped[i - 1] = str[i];
		return (popped);
	}
	return (NULL);
}
