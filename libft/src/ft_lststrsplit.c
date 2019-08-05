/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 09:36:45 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/01 19:18:43 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lststrsplit(t_list *nlst, char const *s, char c)
{
	char	**res;
	t_list	*nelem;
	int		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	res = ft_strsplit(s, c);
	while (res[i])
	{
		nelem = ft_lstnew(res[i], ft_strlen(*res) + 1);
		ft_lstadd(&nlst, nelem);
		i++;
	}
	ft_freearr(res);
	return (nlst);
}
