/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:58:21 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 10:23:57 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	size_t szs2;

	szs2 = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, szs2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
