/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:22:12 by stenner           #+#    #+#             */
/*   Updated: 2019/07/02 11:25:06 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap(void *a, void *b, size_t s)
{
	char *tmp_a;

	tmp_a = ft_memalloc(s);
	ft_memmove(tmp_a, a, s);
	ft_memmove(a, b, s);
	ft_memmove(b, tmp_a, s);
	free(tmp_a);
}
