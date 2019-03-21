/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:55:46 by rpapagna          #+#    #+#             */
/*   Updated: 2019/02/20 06:55:58 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*m;

	i = 0;
	if (!(m = malloc(size)))
		return (NULL);
	ft_bzero(m, size);
	return (m);
}
