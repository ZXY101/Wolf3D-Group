/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:50:25 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 09:45:15 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	dup = NULL;
	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(*dup) * (len + 1));
	if (dup != NULL)
	{
		ft_strcpy(dup, s);
		return (dup);
	}
	else
		return (0);
}
