/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:41:45 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:44:05 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrsrc;
	unsigned char	chr;

	ptrsrc = (unsigned char*)s;
	chr = (unsigned char)c;
	i = 0;
	while (i++ < n)
		if (*(ptrsrc++) == chr)
			return ((void*)--ptrsrc);
	return (0);
}
