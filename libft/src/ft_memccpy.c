/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:29:42 by stenner           #+#    #+#             */
/*   Updated: 2019/05/31 11:50:27 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (src_u[i] == (unsigned char)c)
		{
			dst_u[i] = src_u[i];
			return ((char*)dst + (i + 1));
		}
		dst_u[i] = src_u[i];
		i++;
	}
	return (NULL);
}
