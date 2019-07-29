/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:34:54 by stenner           #+#    #+#             */
/*   Updated: 2019/06/10 11:57:10 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					i;
	unsigned const char *s1u;
	unsigned const char *s2u;

	s1u = (unsigned const char *)s1;
	s2u = (unsigned const char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((s1u[i] != '\0' && s2u[i] != '\0') && ((size_t)i < n - 1))
	{
		if (s1u[i] != s2u[i])
			break ;
		i++;
	}
	return (s1u[i] - s2u[i]);
}
