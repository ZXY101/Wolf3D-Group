/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:46:31 by no-conne          #+#    #+#             */
/*   Updated: 2019/08/06 12:56:35 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	check1a(t_list *map, t_environment *env)
{
	int	flag;

	flag = 0;
	if (env->map_lst_size < 3)
		ft_error("Map too small");
	while (map->next != NULL)
	{
		if ((map->content_size / 2) >= 3)
			flag = 1;
		map = map->next;
	}
	if ((map->content_size / 2) >= 3)
		flag = 1;
	if (flag == 0)
		ft_error("Map too small");
}

void	check4_subf(t_list *map, t_list *map2, char *c_content)
{
	int diff;

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

void	check5_subf(char *c_content, int i)
{
	if ((c_content[i] >= 48 && c_content[i] <= 57) || c_content[i]
	== 'F' || c_content[i] == 'x' || c_content[i] == ' ')
		i++;
	else
		ft_error("Invalid characters in map");
}

void	map_format_subf(size_t i, char *c_content, t_list *map)
{
	if (c_content[i] != ' ')
	{
		if (i == 0 && c_content[i + 1] == ' ')
			i++;
		else if (i == map->content_size - 2 && c_content[i + 1]
		== '\0' && c_content[i - 1] == ' ')
			i++;
		else if (c_content[i + 1] == ' ' && c_content[i - 1] == ' ')
			i++;
		else
			ft_error("Invalid characters in map");
	}
	else
	{
		if (c_content[i + 1] != ' ' && c_content[i - 1] != ' ')
			i++;
		else
			ft_error("Invalid characters in map");
	}
}

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
			map_format_subf(i, c_content, map);
			i++;
		}
		map = map->next;
	}
	c_content = map->content;
	i = 0;
	while (i < map->content_size - 1)
	{
		map_format_subf(i, c_content, map);
		i++;
	}
}
