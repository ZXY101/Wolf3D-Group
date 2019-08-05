/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 01:56:25 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 10:06:29 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	sl;
	char			*str;
	unsigned int	i;

	if (s)
	{
		sl = ft_strlen(s);
		if (start + len > sl)
			return (NULL);
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		i = 0;
		while (len--)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
