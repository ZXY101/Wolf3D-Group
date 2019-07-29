/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:03:47 by stenner           #+#    #+#             */
/*   Updated: 2019/06/11 15:52:15 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

long	ft_power(long base, long exp)
{
	long i;
	long result;

	i = 0;
	result = 1;
	if (!(exp >= 0))
		return (0);
	if (exp == 0)
		return (1);
	while (i < exp)
	{
		result = result * base;
		i++;
	}
	return (result);
}
