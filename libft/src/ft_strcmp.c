/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:07:02 by stenner           #+#    #+#             */
/*   Updated: 2019/05/23 09:56:21 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	unsigned const char *s1u;
	unsigned const char *s2u;

	s1u = (unsigned const char *)s1;
	s2u = (unsigned const char *)s2;
	i = 0;
	while (s1u[i] != '\0' && s2u[i] != '\0')
	{
		if (s1u[i] != s2u[i])
			break ;
		i++;
	}
	return (s1u[i] - s2u[i]);
}
