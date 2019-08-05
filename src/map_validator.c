/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:18:37 by no-conne          #+#    #+#             */
/*   Updated: 2019/08/05 14:35:38 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	check1(int fd)
{
	if (fd < 0)
		ft_error("Could not acces map");
}

void	check2(t_list *map)
{
	t_list	*tmp_map;

	tmp_map = map;
	if (ft_strchr(tmp_map->content, '0'))
		ft_error("invalid map, first row cannot have a 0 in it");
	while (tmp_map->next != NULL)
		tmp_map = tmp_map->next;
	if (ft_strchr(tmp_map->content, '0'))
		ft_error("invalid map, last row cannot have a 0 in it");
}

void	check3(t_list *map)
{
	char	*c_content;

	while (map->next != NULL)
	{
		c_content = map->content;
		if (c_content[0] == '0' || c_content[map->content_size - 2] == '0')
			ft_error("Invalid map, border cannot contain 0");
		map = map->next;
	}
}

void	check4(t_list *map)
{
	char	*c_content;
	char	*c_content2;
	int		diff;
	t_list	*map2;

	map2 = map->next;
	while (map2->next != NULL)
	{
		c_content = map->content;
		c_content2 = map2->content;
		if (map->content_size > map2->content_size)
		{
			diff = map->content_size - map2->content_size;
			while (diff-- != 0)
			{
				if (c_content[map->content_size - diff] == '0')
					ft_error("Invalid map, 0's must be surrounded by nums");
			}
		}
		map = map->next;
		map2 = map2->next;
	}
	c_content = map->content;
	c_content2 = map2->content;
	if (map->content_size > map2->content_size)
	{
		diff = map->content_size - map2->content_size;
		while (diff-- != 0)
		{
			if (c_content[map->content_size - diff] == '0')
				ft_error("Invalid map, 0's must be surrounded by nums");
		}
	}
}

void	check5(t_list *map)
{
	char		*c_content;
	size_t		i;

	while (map->next != NULL)
	{
		c_content = map->content;
		i = 0;
		while (i < map->content_size - 1)
		{
			if ((c_content[i] >= 48 && c_content[i] <= 57) || c_content[i]
			== 'F' || c_content[i] == 'x' || c_content[i] == ' ')
				i++;
			else
				ft_error("Invalid characters in map");
		}
		map = map->next;
	}
	c_content = map->content;
	i = 0;
	while (i < map->content_size - 1)
	{
		if ((c_content[i] >= 48 && c_content[i] <= 57) || c_content[i] == 'F'
		|| c_content[i] == 'x' || c_content[i] == ' ')
			i++;
		else
			ft_error("Invalid characters in map");
	}
}
