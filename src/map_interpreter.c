/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interpreter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:41:53 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/30 13:58:28 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_list	*map_interpreter(const char *path)
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
		free(line);
	}
	tmp = map;
	tmp = tmp->next;
	free(map);
	map = tmp;
	close(fd);
	return (map);
}
