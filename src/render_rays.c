/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:29:23 by stenner           #+#    #+#             */
/*   Updated: 2019/08/05 09:05:05 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	initialise_vars(t_environment *env, int x)
{
	env->rd.camera.x = 2 * x / (double)WINDOW_LENGTH - 1;
	env->rd.ray_dir.x = env->dir.x + env->plane.x * env->rd.camera.x;
	env->rd.ray_dir.y = env->dir.y + env->plane.y * env->rd.camera.x;
	env->rd.map_x = (int)env->pos.x;
	env->rd.map_y = (int)env->pos.y;
	env->rd.ddx = fabs(1 / env->rd.ray_dir.x);
	env->rd.ddy = fabs(1 / env->rd.ray_dir.y);
	env->rd.hit = 0;
}

void	calc_step_sd(t_environment *env)
{
	if (env->rd.ray_dir.x < 0)
	{
		env->rd.step_x = -1;
		env->rd.side_dist_x = (env->pos.x - env->rd.map_x) * env->rd.ddx;
	}
	else
	{
		env->rd.step_x = 1;
		env->rd.side_dist_x = (env->rd.map_x + 1.0 - env->pos.x) * env->rd.ddx;
	}
	if (env->rd.ray_dir.y < 0)
	{
		env->rd.step_y = -1;
		env->rd.side_dist_y = (env->pos.y - env->rd.map_y) * env->rd.ddy;
	}
	else
	{
		env->rd.step_y = 1;
		env->rd.side_dist_y = (env->rd.map_y + 1.0 - env->pos.y) * env->rd.ddy;
	}
}

void	exec_dda(t_environment *env)
{
	while (env->rd.hit == 0)
	{
		if (env->rd.side_dist_x < env->rd.side_dist_y)
		{
			env->rd.side_dist_x += env->rd.ddx;
			env->rd.map_x += env->rd.step_x;
			env->rd.side = 0;
		}
		else
		{
			env->rd.side_dist_y += env->rd.ddy;
			env->rd.map_y += env->rd.step_y;
			env->rd.side = 1;
		}
		if (env->map[env->rd.map_x][env->rd.map_y] > 0)
			env->rd.hit = 1;
	}
}

void	calc_lh_wd(t_environment *env)
{
	if (env->rd.side == 0)
		env->rd.pwd = (env->rd.map_x - env->pos.x +
		(1 - env->rd.step_x) / 2) / env->rd.ray_dir.x;
	else
		env->rd.pwd = (env->rd.map_y - env->pos.y +
		(1 - env->rd.step_y) / 2) / env->rd.ray_dir.y;
	env->rd.line_height = (int)(WINDOW_HEIGHT / env->rd.pwd);
	env->rd.draw_start.y = -env->rd.line_height / 2 + WINDOW_HEIGHT / 2;
	if (env->rd.draw_start.y < 0)
		env->rd.draw_start.y = 0;
	env->rd.draw_end.y = env->rd.line_height / 2 + WINDOW_HEIGHT / 2;
	if (env->rd.draw_end.y >= WINDOW_HEIGHT)
		env->rd.draw_end.y = WINDOW_HEIGHT - 1;
}
