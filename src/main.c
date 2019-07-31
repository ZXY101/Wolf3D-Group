/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/31 09:45:50 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>


int		main(int ac, char **av)
{
	t_environment	env;
	char	*file;
	
	if (ac > 2 || ac < 1)
		ft_error("Usage ./Wolf3d <map>");
	file = (ac > 1) ? av[1] : main_menu();
	(void)file;
	//This is where we load the file 
	//LOADFILE THINGY ..
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"wolf3d");
	init_image(&env, &env.img, WINDOW_LENGTH, WINDOW_HEIGHT);
	// GET POS FROM MAP??
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

void		ft_error(char *str)
{
	char	*prompt;

	prompt = ft_strjoin("\e[91m", "[ERROR]\t\t\t");
	prompt = ft_strjoin_free(prompt, str, 1, 0);
	prompt = ft_strjoin_free(prompt, "\33[m", 1, 0);
	ft_putendl_fd(prompt, 2);
	free(prompt);
	exit(-1);
}