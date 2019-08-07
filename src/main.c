/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:27 by stenner           #+#    #+#             */
/*   Updated: 2019/08/06 14:44:55 by stenner          ###   ########.fr       */
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
	char			*file;

	if (ac > 2 || ac < 1)
		ft_error("Usage ./Wolf3d <map>");
	file = (ac > 1) ? av[1] : main_menu();
	if (!ft_strstr(file, ".map\0"))
		ft_error("Invalid map!");
	init_env(&env);
	map = map_interpreter(file, &env);
	map_int_array(map, &env);
	check6(&env);
	ft_lstdel(&map, del);
	sdl_audio_init();
	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	sdl_audio_exit(&env.menu);
	return (0);
}
