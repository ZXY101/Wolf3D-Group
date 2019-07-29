/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:39:19 by stenner           #+#    #+#             */
/*   Updated: 2019/06/10 15:32:21 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_elements(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static char	**make_array(char const *s, char c, int element_count, char **array)
{
	struct s_vars a;

	a.i = 0;
	a.j = 0;
	while (a.i < element_count)
	{
		a.char_count = 0;
		while (s[a.j] == c)
			a.j++;
		a.start = a.j;
		while (s[a.j] != c && s[a.j++] != '\0')
			a.char_count++;
		a.str = (char*)malloc(sizeof(char) * (a.char_count + 1));
		if (!a.str)
			return (NULL);
		ft_memcpy(a.str, s + a.start, a.char_count);
		a.str[a.char_count] = '\0';
		array[a.i] = ft_strdup(a.str);
		ft_strclr(a.str);
		ft_strdel(&a.str);
		a.i++;
	}
	array[a.i] = NULL;
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	int		element_count;
	char	**array;

	if (!s || !c)
		return (NULL);
	element_count = count_elements(s, c);
	array = (char**)malloc(sizeof(char*) * element_count + 1);
	if (!array)
		return (NULL);
	array = make_array(s, c, element_count, array);
	if (!array)
		return (NULL);
	return (array);
}
