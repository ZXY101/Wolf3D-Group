/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:47:28 by stenner           #+#    #+#             */
/*   Updated: 2019/08/05 11:27:36 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		movement(t_environment *env)
{
	env->rot_speed = 3 * env->dt;
	env->move_speed = env->keys[MLX_SHIFT] ? 10 * env->dt : 5 * env->dt;
	if (env->keys[MLX_W] || env->keys[MLX_ARROWUP])
	{
		if (!env->map[(int)((env->pos.x + env->dir.x *
		env->move_speed * 1.8))][(int)env->pos.y])
			env->pos.x += (env->dir.x) * env->move_speed;
		if (!env->map[(int)env->pos.x][(int)((env->pos.y + env->dir.y *
		env->move_speed * 1.8))])
			env->pos.y += env->dir.y * env->move_speed;
	}
	if (env->keys[MLX_S] || env->keys[MLX_ARROWDOWN])
	{
		if (!env->map[(int)(env->pos.x - env->dir.x *
		env->move_speed * 1.8)][(int)env->pos.y])
			env->pos.x -= env->dir.x * env->move_speed;
		if (!env->map[(int)env->pos.x][(int)(env->pos.y - env->dir.y *
		env->move_speed * 1.8)])
			env->pos.y -= env->dir.y * env->move_speed;
	}
}

static void	rotate_right(t_environment *env)
{
	double		old_dir_x;
	double		old_plane_x;

	if (env->keys[MLX_D] || env->keys[MLX_ARROWR])
	{
		old_dir_x = env->dir.x;
		env->dir.x = env->dir.x * cos(-env->rot_speed) -
		env->dir.y * sin(-env->rot_speed);
		env->dir.y = old_dir_x * sin(-env->rot_speed) +
		env->dir.y * cos(-env->rot_speed);
		old_plane_x = env->plane.x;
		env->plane.x = env->plane.x * cos(-env->rot_speed) -
		env->plane.y * sin(-env->rot_speed);
		env->plane.y = old_plane_x * sin(-env->rot_speed) +
		env->plane.y * cos(-env->rot_speed);
	}
}

static void	rotate_left(t_environment *env)
{
	double		old_dir_x;
	double		old_plane_x;

	if (env->keys[MLX_A] || env->keys[MLX_ARROWL])
	{
		old_dir_x = env->dir.x;
		env->dir.x = env->dir.x * cos(env->rot_speed) -
		env->dir.y * sin(env->rot_speed);
		env->dir.y = old_dir_x * sin(env->rot_speed) +
		env->dir.y * cos(env->rot_speed);
		old_plane_x = env->plane.x;
		env->plane.x = env->plane.x * cos(env->rot_speed) -
		env->plane.y * sin(env->rot_speed);
		env->plane.y = old_plane_x * sin(env->rot_speed) +
		env->plane.y * cos(env->rot_speed);
	}
}

void		rotation(t_environment *env)
{
	rotate_left(env);
	rotate_right(env);
}
