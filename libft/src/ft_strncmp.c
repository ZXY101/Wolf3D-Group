/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:22:13 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/05/24 10:32:54 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	sz1;
	size_t	sz2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	sz2 = ft_strlen(s1);
	sz1 = ft_strlen(s2);
	if (sz1 >= sz2)
		i = sz1;
	else
		i = sz2;
	if (i > n)
		i = n;
	return (ft_memcmp(s1, s2, i));
}
