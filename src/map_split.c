/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 08:11:57 by no-conne          #+#    #+#             */
/*   Updated: 2019/08/07 08:02:58 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	check6(t_environment *env)
{
	if (env->x_count == 0)
		ft_error("No start point");
}

void	pos_update(char **map_data, int c, int i, t_environment *env)
{
	if (map_data[c][0] == 'x')
	{
		env->pos.x = i + 0.5;
		env->pos.y = c + 0.5;
		env->x_count++;
	}
}

void	map_int_array(t_list *lst, t_environment *env)
{
	int		i;
	int		c;
	char	**map_data;

	i = 0;
	if (!(env->map = (int **)malloc(sizeof(int *) * env->map_lst_size)))
		ft_error("malloc error");
	while (i < env->map_lst_size)
	{
		c = -1;
		if (!(env->map[i] = (int *)malloc(sizeof(int) *
		(int)(lst->content_size / 2))))
			ft_error("malloc error");
		map_data = ft_strsplit(lst->content, ' ');
		while (++c < (int)(lst->content_size / 2))
		{
			pos_update(map_data, c, i, env);
			env->map[i][c] = ft_atoi(map_data[c]);
			free(map_data[c]);
		}
		free(map_data);
		if (lst->next != NULL)
			lst = lst->next;
		i++;
	}
}
