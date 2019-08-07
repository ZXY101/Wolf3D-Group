/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interpreter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:41:53 by no-conne          #+#    #+#             */
/*   Updated: 2019/08/06 14:46:22 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	checks(t_list *map, int fd, t_environment *env)
{
	check1(fd);
	check1a(map, env);
	check2(map);
	check3(map);
	check4(map);
	check5(map);
	map_format(map);
}

t_list	*empty_check(t_list *tmp)
{
	if (tmp->next)
		tmp = tmp->next;
	else
		ft_error("No map avaialble");
	return (tmp);
}

t_list	*map_interpreter(const char *path, t_environment *env)
{
	t_list	*map;
	t_list	*tmp;
	char	*line;
	int		fd;

	map = ft_lstnew(NULL, 0);
	fd = open(path, O_RDONLY);
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
	tmp = empty_check(tmp);
	free(map);
	map = tmp;
	checks(map, fd, env);
	close(fd);
	return (map);
}
