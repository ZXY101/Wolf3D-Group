/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interpreter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:41:53 by no-conne          #+#    #+#             */
/*   Updated: 2019/08/05 12:58:54 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	checks(t_list *map)
{
	check2(map);
	check3(map);
	check4(map);
}

t_list	*map_interpreter(const char *path, t_environment *env)
{
	t_list	*map;
	t_list	*tmp;
	char	*line;
	int		fd;

	map = ft_lstnew(NULL, 0);
	fd = open(path, O_RDONLY);
	check1(fd);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = map;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew(line, ft_strlen(line) + 1);
		env->map_lst_size++;
		free(line);
	}
	tmp = map;
	tmp = tmp->next;
	free(map);
	map = tmp;
	checks(map);
	close(fd);
	return (map);
}

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
			if (map_data[c][0] == 'x')
			{
				env->pos.x = i + 0.5;
				env->pos.y = c + 0.5;
			}
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
