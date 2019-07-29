/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:44:04 by stenner           #+#    #+#             */
/*   Updated: 2019/05/31 11:50:38 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	c_u;
	unsigned char	*s_u;

	i = 0;
	c_u = (unsigned char)c;
	s_u = (unsigned char *)s;
	while ((size_t)i < n)
	{
		if (s_u[i] == c_u)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
