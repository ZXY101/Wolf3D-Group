/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:37:37 by stenner           #+#    #+#             */
/*   Updated: 2019/07/30 10:03:20 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int map[MAP_WIDTH][MAP_HEIGHT]=
{
  {3,1,2,3,1,2,3,2,1,1,3,1,2,3,4,4,7,7,7,7,7,7,7,7},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,1,2,3,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,1,2,3,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,1,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,2,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,3,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void	pop_map_placeholder(t_environment *env)
{
	int x = 0;
	int y;

	while (x < MAP_WIDTH)
	{
		y = 0;
		while (y < MAP_HEIGHT)
		{
			env->map[x][y] = map[x][y];
			y++;
		}
		x++;
	}
}

void	init_env(t_environment *env)
{
	env->mlx_ptr = mlx_init();
	ft_init_tex(env);
	ft_validate_tex(env);
	ft_load_tex(env);
	pop_map_placeholder(env);
	env->win_ptr = mlx_new_window(env->mlx_ptr, WINDOW_LENGTH, WINDOW_HEIGHT,
	"wolf3d");
	init_image(env, &env->img, WINDOW_LENGTH, WINDOW_HEIGHT);
	env->pos.x = 22;
	env->pos.y = 11.5;
	env->dir.x = -1;
	env->dir.y = 0;
	env->plane.x = 0;
	env->plane.y = 0.66;
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
	mlx_string_put(env->mlx_ptr, env->win_ptr,10,5, 0xffffff,"FPS: ");
	mlx_string_put(env->mlx_ptr, env->win_ptr,50,5, 0xffffff,str);
	free(str);
}
