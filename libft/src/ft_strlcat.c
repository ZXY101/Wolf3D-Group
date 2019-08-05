/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:32:22 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:46:40 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		tlen;
	size_t		srclen;
	size_t		dstlen;
	size_t		lp;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	tlen = srclen + dstlen;
	if (size <= dstlen)
		return (srclen + size);
	while (*dst)
		dst++;
	lp = 0;
	while ((lp < size - (tlen - srclen) - 1) && src[lp])
	{
		dst[lp] = src[lp];
		lp++;
	}
	dst[lp] = '\0';
	return (tlen);
}
