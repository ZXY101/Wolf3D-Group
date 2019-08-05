/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:27:42 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 10:00:09 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		sz1;
	int		sz2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	sz2 = ft_strlen(s1);
	sz1 = ft_strlen(s2);
	if (sz1 >= sz2)
		i = sz1;
	else
		i = sz2;
	return (ft_memcmp(s1, s2, i));
}
