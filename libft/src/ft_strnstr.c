/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:51:29 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 10:22:04 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t szs2;

	szs2 = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && n >= szs2)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, szs2) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
