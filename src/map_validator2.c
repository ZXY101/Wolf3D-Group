/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:46:31 by no-conne          #+#    #+#             */
/*   Updated: 2019/08/05 15:14:28 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

//void	check4sub()
//void	check5sub()

void	map_format(t_list *map)
{
	char		*c_content;
	size_t		i;

	while (map->next != NULL)
	{
		c_content = map->content;
		i = 0;
		while (i < map->content_size - 1)
		{
			if (c_content[i] != ' ')
			{
				if (c_content[i + 1] == ' ' && c_content[i - 1] == ' ')
					i++;
				else
					ft_error("Invalid characters in map");
			}
			else
				i++;
		}
		map = map->next;
	}
	c_content = map->content;
	i = 0;
	while (i < map->content_size - 1)
	{
		if (c_content[i] != ' ')
		{
			if (c_content[i + 1] == ' ' && c_content[i - 1] == ' ')
				i++;
			else
				ft_error("Invalid characters in map");
		}
		else
			i++;
	}
}

void	check0(t_list *map)
{
	if(map->content == NULL)
		ft_error("Empty map");
}