/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:14:07 by stenner           #+#    #+#             */
/*   Updated: 2019/07/29 12:16:16 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int free1, int free2)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	if (free1)
		free(s1);
	if (free2)
		free(s2);
	return (ret);
}
