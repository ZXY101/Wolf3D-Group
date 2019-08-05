/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:20:19 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 09:48:24 by rcoetzer         ###   ########.fr       */
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
