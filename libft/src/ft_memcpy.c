/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:42:15 by stenner           #+#    #+#             */
/*   Updated: 2019/05/31 11:53:03 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					i;
	unsigned char		*dst_u;
	unsigned const char	*src_u;

	i = 0;
	dst_u = (unsigned char *)dst;
	src_u = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while ((size_t)i < n)
	{
		dst_u[i] = src_u[i];
		i++;
	}
	return (dst);
}
