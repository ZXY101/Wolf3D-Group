/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:30:33 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/06/07 10:54:51 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long nb)
{
	int		sz;

	sz = 0;
	if (nb < 0)
	{
		nb *= -1;
		sz++;
	}
	while (nb > 0)
	{
		nb /= 10;
		sz++;
	}
	return (sz);
}

char		*ft_itoa(int nb)
{
	char	*str;
	long	lnb;
	int		i;

	lnb = nb;
	i = ft_numlen(lnb);
	if (!(str = (char*)malloc(sizeof(str) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (lnb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (lnb < 0)
	{
		str[0] = '-';
		lnb *= -1;
	}
	while (lnb > 0)
	{
		str[i--] = (lnb % 10) + '0';
		lnb /= 10;
	}
	return (str);
}
