/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:27 by stenner           #+#    #+#             */
/*   Updated: 2019/07/29 10:13:02 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"


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

	t_mlx_image eish;
	init_image(&env, &eish, WINDOW_LENGTH, WINDOW_HEIGHT);

	env.textures[0].height = 64;
	env.textures[0].width = 64;
	env.textures[0].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/left.xpm", &env.textures[0].width, &env.textures[0].height);
	env.textures[0].data = (int*)mlx_get_data_addr(env.textures[0].img, &eish.bpp, &eish.size_line, &eish.endian);

	env.textures[1].height = 64;
	env.textures[1].width = 64;
	env.textures[1].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/middle.xpm", &env.textures[1].width, &env.textures[1].height);
	env.textures[1].data = (int*)mlx_get_data_addr(env.textures[1].img, &eish.bpp, &eish.size_line, &eish.endian);

	env.textures[2].height = 64;
	env.textures[2].width = 64;
	env.textures[2].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/right.xpm", &env.textures[2].width, &env.textures[2].height);
	env.textures[2].data = (int*)mlx_get_data_addr(env.textures[2].img, &eish.bpp, &eish.size_line, &eish.endian);

	env.textures[3].height = 64;
	env.textures[3].width = 64;
	env.textures[3].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/greystone.xpm", &env.textures[3].width, &env.textures[3].height);
	env.textures[3].data = (int*)mlx_get_data_addr(env.textures[3].img, &eish.bpp, &eish.size_line, &eish.endian);

	env.textures[4].height = 64;
	env.textures[4].width = 64;
	env.textures[4].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/eagle.xpm", &env.textures[4].width, &env.textures[4].height);
	env.textures[4].data = (int*)mlx_get_data_addr(env.textures[4].img, &eish.bpp, &eish.size_line, &eish.endian);

	env.textures[5].height = 64;
	env.textures[5].width = 64;
	env.textures[5].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/mossy.xpm", &env.textures[5].width, &env.textures[5].height);
	env.textures[5].data = (int*)mlx_get_data_addr(env.textures[5].img, &eish.bpp, &eish.size_line, &eish.endian);

	env.textures[6].height = 64;
	env.textures[6].width = 64;
	env.textures[6].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/redbrick.xpm", &env.textures[6].width, &env.textures[6].height);
	env.textures[6].data = (int*)mlx_get_data_addr(env.textures[6].img, &eish.bpp, &eish.size_line, &eish.endian);

	env.textures[7].height = 64;
	env.textures[7].width = 64;
	env.textures[7].img = mlx_xpm_file_to_image(env.mlx_ptr, "textures/purplestone.xpm", &env.textures[7].width, &env.textures[7].height);
	env.textures[7].data = (int*)mlx_get_data_addr(env.textures[7].img, &eish.bpp, &eish.size_line, &eish.endian);

	handle_hooks(env.win_ptr, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
