/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:44:06 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:43:23 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	ptrdst = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	i = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		if ((*ptrdst++ = *ptrsrc++) == c)
			return (ptrdst);
		i++;
	}
	return (NULL);
}
