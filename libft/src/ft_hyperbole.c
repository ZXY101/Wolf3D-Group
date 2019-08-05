/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hyperbole.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 07:43:45 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/04 08:13:36 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_hyperbole(double x, double exp, double div)
{
	if (div == 0 || !x || !exp || !div)
		return (0);
	return (pow(x, exp) / div);
}
