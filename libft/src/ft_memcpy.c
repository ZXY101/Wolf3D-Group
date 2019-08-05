/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:43:43 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:42:57 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (n == 0 || dest == src)
		return (dest);
	i = -1;
	while (++i < n)
		*((char *)dest + i) = *((char *)src + i);
	return (dest);
}
