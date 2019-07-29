/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/29 13:17:07 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>


int		main(void)
{
	t_environment	env;
	

	

	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"wolf3d");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	env.pos.x = 22;
	env.pos.y = 11.5;
	env.dir.x = -1;
	env.dir.y = 0;
	env.plane.x = 0;
	env.plane.y = 0.66;
	gettimeofday(&env.old_time, NULL);
	
	ft_init_tex(&env);
	ft_validate_tex(&env);
	ft_load_tex(&env);

	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
