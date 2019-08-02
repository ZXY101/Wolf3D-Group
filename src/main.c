/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:27 by stenner           #+#    #+#             */
/*   Updated: 2019/08/01 14:31:30 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	del(void *node, size_t n)
{
	(void)n;
	free(node);
}

int		main(int ac, char **av)
{
	t_list			*map;
	t_environment	env;
	Uint8			*dst = NULL;
	Uint32			len = 0;
	SDL_MixAudio(dst, dst, len, 30);
	char			*file;
	
	if (ac > 2 || ac < 1)
		ft_error("Usage ./Wolf3d <map>");
	file = (ac > 1) ? av[1] : main_menu();
	init_env(&env);
	map = map_interpreter(file, &env);
 	map_int_array(map, &env);
	ft_lstdel(&map,del);
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
