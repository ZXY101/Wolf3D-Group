/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:43:44 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/12 15:12:03 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t len)
{
	void	*new;

	new = malloc(len);
	ft_memset(new, 0, len);
	if (new)
		ft_memcpy(new, ptr, len);
	if (ptr)
		free(ptr);
	return (new);
}
