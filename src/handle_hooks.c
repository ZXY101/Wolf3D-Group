/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/08/05 12:53:05 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file has all of the functions that handle events
*/

#include <wolf3d.h>

/*
**Quit the program when the close button is clicked
*/

static int	finish(void *none)
{
	(void)none;
	exit(0);
}

int			key_down(int key, t_environment *env)
{
	if (key == MLX_ESC)
		exit(0);
	env->keys[key] = 1;
	return (0);
}

int			key_release(int key, t_environment *env)
{
	env->keys[key] = 0;
	return (0);
}

int			fun(t_environment *env)
{
	int x;

	clear_image(&env->img, rgbtoi(0, 0, 0));
	update_dt(env);
	x = 0;
	while (x < WINDOW_LENGTH)
	{
		initialise_vars(env, x);
		calc_step_sd(env);
		exec_dda(env);
		calc_lh_wd(env);
		calc_textures(env);
		draw_walls(env, x);
		draw_floor(env, x);
		x++;
	}
	put_image(env, &env->img);
	printf_fps(env);
	movement(env);
	rotation(env);
	play_music(&env->menu, "sounds/loop.wav");
	return (0);
}

/*
**All of the hooks
*/

void		handle_hooks(void *win_ptr, t_environment *env)
{
	mlx_hook(win_ptr, 2, 1L << 0, key_down, env);
	mlx_hook(win_ptr, 3, 1L << 1, key_release, env);
	mlx_hook(win_ptr, 17, 1L, finish, env);
	mlx_loop_hook(env->mlx_ptr, fun, env);
}
