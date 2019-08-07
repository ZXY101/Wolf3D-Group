/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:01:21 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/06 14:47:54 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		init_env(t_environment *env)
{
	env->mlx_ptr = mlx_init();
	ft_init_tex(env);
	ft_validate_tex(env);
	ft_load_tex(env);
	env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"wolf3d");
	init_image(env, &env->img, WINDOW_LENGTH, WINDOW_HEIGHT);
	env->dir.x = -1;
	env->dir.y = 0;
	env->plane.x = 0;
	env->plane.y = 0.66;
	env->map_lst_size = 0;
	env->x_count = 0;
	gettimeofday(&env->old_time, NULL);
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

void		update_dt(t_environment *env)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	env->dt = (time.tv_sec - env->old_time.tv_sec);
	env->dt += (time.tv_usec - env->old_time.tv_usec) / 1000000.0;
	ft_memcpy(&env->old_time, &time, sizeof(t_timeval));
}

void		printf_fps(t_environment *env)
{
	char *str;

	str = ft_itoa(1 / env->dt);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 5, 0xffffff, "FPS: ");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 50, 5, 0xffffff, str);
	free(str);
}
