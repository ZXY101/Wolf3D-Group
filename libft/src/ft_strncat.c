/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:55:27 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:46:18 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		szs1;
	size_t		i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	i = 0;
	szs1 = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[szs1] = ((char *)s2)[i];
		szs1++;
		i++;
	}
	s1[szs1] = '\0';
	return (s1);
}
