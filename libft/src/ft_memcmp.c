/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:16:25 by stenner           #+#    #+#             */
/*   Updated: 2019/05/31 11:52:40 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					i;
	const unsigned char	*s1_u;
	const unsigned char	*s2_u;

	i = 0;
	s1_u = (const unsigned char*)s1;
	s2_u = (const unsigned char*)s2;
	if (n == 0 || s1 == s2)
		return (0);
	while ((size_t)i < n)
	{
		if (s1_u[i] != s2_u[i])
			return (s1_u[i] - s2_u[i]);
		i++;
	}
	return (0);
}
