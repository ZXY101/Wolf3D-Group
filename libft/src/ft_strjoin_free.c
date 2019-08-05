/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:03:18 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 09:47:54 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2, int free1, int free2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (free1)
		free(s1);
	if (free2)
		free(s2);
	return (ret);
}
