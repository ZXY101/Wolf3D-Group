/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:47:51 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 11:18:14 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(const char *s, char c)
{
	int			iswrd;
	int			wordc;

	iswrd = 0;
	wordc = 0;
	while (*s != '\0')
	{
		if (*s != c && iswrd == 0)
		{
			iswrd = 1;
			wordc++;
		}
		if (*s == c && iswrd == 1)
			iswrd = 0;
		s++;
	}
	return (wordc);
}

static int		ft_wordlen(const char *s, char d)
{
	int			len;

	len = 0;
	while (*s != '\0' && *s != d)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			word;
	int			i;

	i = 0;
	if (!s)
		return (0);
	word = ft_wordcount(s, c);
	str = (char**)malloc(sizeof(*str) * (ft_wordcount(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (word > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (str[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
		word--;
	}
	str[i] = NULL;
	return (str);
}
