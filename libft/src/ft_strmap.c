/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 01:38:34 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 10:05:54 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*mem;
	size_t	i;
	size_t	sl;

	if (s && f)
	{
		sl = ft_strlen(s);
		mem = ft_strnew(sl);
		if (!mem)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			mem[i] = (*f)(s[i]);
			i++;
		}
		return (mem);
	}
	return (NULL);
}
