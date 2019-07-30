/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/30 13:58:46 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	del(void *node, size_t n)
{
	(void)n;
	free(node);
}

int		main(void)
{
	t_list	*map;
	t_environment	env;
	map = map_interpreter("map.map");
	ft_lstdel(&map,del);
	init_env(&env);
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
