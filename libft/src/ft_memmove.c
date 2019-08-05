/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:47:11 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:43:45 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptrdst = dest;
	ptrsrc = src;
	if (ptrdst > ptrsrc)
	{
		i = n;
		while (i > 0)
		{
			ptrdst[i - 1] = ptrsrc[i - 1];
			i--;
		}
	}
	else if (ptrdst < ptrsrc)
		ft_memcpy(dest, src, n);
	return (dest);
}
