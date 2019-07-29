/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:34:29 by stenner           #+#    #+#             */
/*   Updated: 2019/05/31 11:53:38 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*temp_b;

	i = 0;
	temp_b = (char *)b;
	while ((size_t)i < len)
	{
		temp_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
