/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:11:57 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/31 12:43:35 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	map_int_array(t_list *lst, t_environment *env)
{
	int		i;
	int		c;
	char	**map_data;

	i = 0;
	if (!(env->map = (int **)malloc(sizeof(int *) * env->map_lst_size)))
		exit(0);
	while (i < env->map_lst_size)
	{
		c = 0;
		if (!(env->map[i] = (int *)malloc(sizeof(int) *
		(int)(lst->content_size / 2))))
			exit(0);
		map_data = ft_strsplit(lst->content, ' ');
		while (c < (int)(lst->content_size / 2))
		{
			env->map[i][c] = ft_atoi(map_data[c]);
			free(map_data[c]);
			c++;
		}
		free(map_data);
		i++;
		if (lst->next != NULL)
			lst = lst->next;
	}
}
