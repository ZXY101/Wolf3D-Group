/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:28:02 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:46:01 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		sz1;
	int		sz2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	sz2 = 0;
	sz1 = ft_strlen(s1);
	while (s2[sz2] != '\0')
	{
		s1[sz1 + sz2] = s2[sz2];
		sz2++;
	}
	s1[sz1 + sz2] = '\0';
	return (s1);
}
