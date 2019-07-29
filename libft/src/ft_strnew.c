/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:51:54 by stenner           #+#    #+#             */
/*   Updated: 2019/05/31 11:58:39 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char*)malloc((sizeof(char) * size) + 1);
	if (!str)
		return (NULL);
	else
	{
		ft_memset(str, '\0', size + 1);
	}
	return (str);
}
