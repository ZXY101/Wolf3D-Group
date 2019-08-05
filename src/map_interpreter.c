/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interpreter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:41:53 by no-conne          #+#    #+#             */
/*   Updated: 2019/08/05 11:30:41 by no-conne         ###   ########.fr       */
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
