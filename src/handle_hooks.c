/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:01 by stenner           #+#    #+#             */
/*   Updated: 2019/07/29 16:36:08 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file has all of the functions that handle events
*/

#include <wolf3d.h>

/*
**Quit the program when the close button is clicked
*/

// int map[MAP_WIDTH][MAP_HEIGHT]=
// {
//   {3,1,2,3,1,2,3,2,1,1,3,1,2,3,4,4,7,7,7,7,7,7,7,7},
//   {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,1},
//   {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
//   {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
//   {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
//   {4,0,4,0,0,0,0,5,5,5,1,2,3,5,5,5,7,7,0,7,7,7,7,7},
//   {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
//   {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//   {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
//   {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
//   {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
//   {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
//   {6,6,6,1,2,3,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//   {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
//   {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
//   {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
//   {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
//   {4,0,0,5,0,0,0,0,0,4,6,0,1,2,0,0,0,0,0,2,2,0,2,2},
//   {4,0,6,0,6,0,0,0,0,4,6,0,2,2,0,0,5,0,0,2,0,0,0,2},
//   {4,0,0,0,0,0,0,0,0,4,6,0,3,2,0,0,0,0,0,2,0,0,0,2},
//   {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
// };

static int	finish(void *none)
{
	(void)none;
	exit(0);
}

int		key_down(int key, t_environment *env)
{
	
	if (key == 53)
		exit(0);
	env->keys[key] = 1;
	return (0);
}

int		key_release(int key, t_environment *env)
{
	env->keys[key] = 0;
	return (0);
}

int		fun(t_environment *env)
{
	int x;
	t_vector 	camera;
	t_vector 	ray_dir;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	t_vector	draw_start;
	t_vector	draw_end;
	double		move_speed;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;
	int			text_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	int			d;
	unsigned int	colour;
	t_timeval	time;

	clear_image(&env->img, rgbtoi(0, 0, 0));
	gettimeofday(&time, NULL);
	env->delta_time = (time.tv_sec - env->old_time.tv_sec);
	env->delta_time += (time.tv_usec - env->old_time.tv_usec) / 1000000.0;
	ft_memcpy(&env->old_time, &time, sizeof(t_timeval));

	x = 0;
	while (x < WINDOW_LENGTH)
	{
		camera.x = 2 * x / (double)WINDOW_LENGTH - 1;
		ray_dir.x = env->dir.x + env->plane.x * camera.x;
		ray_dir.y = env->dir.y + env->plane.y * camera.x;

		map_x = (int)env->pos.x;
		map_y = (int)env->pos.y;

		delta_dist_x = fabs(1 / ray_dir.x);
		delta_dist_y = fabs(1 / ray_dir.y);

		hit = 0;

		if (ray_dir.x < 0)
		{
			step_x = -1;
			side_dist_x = (env->pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - env->pos.x) * delta_dist_x;
		}

		if (ray_dir.y < 0)
		{
			step_y = -1;
			side_dist_y = (env->pos.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - env->pos.y) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (env->map[map_x][map_y] > 0)
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (map_x - env->pos.x + (1 - step_x) / 2) / ray_dir.x;
		else
			perp_wall_dist = (map_y - env->pos.y + (1 - step_y) / 2) / ray_dir.y;

		line_height = (int)(WINDOW_HEIGHT / perp_wall_dist);

		draw_start.y = -line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_start.y < 0)
			draw_start.y = 0;
		draw_end.y = line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_end.y >= WINDOW_HEIGHT)
			draw_end.y = WINDOW_HEIGHT - 1;

		text_num = env->map[map_x][map_y] - 1;

		if (side == 0)
			wall_x = env->pos.y + perp_wall_dist * ray_dir.y;
		else
			wall_x = env->pos.x + perp_wall_dist * ray_dir.x;
		wall_x -=	floor((wall_x))	;

		tex_x = (int)(wall_x * (double)(env->tex[text_num].x));
		if (side == 0 && ray_dir.x > 0)
			tex_x = env->tex[text_num].x - tex_x - 1;
		if (side == 1 && ray_dir.y < 0)
			tex_x = env->tex[text_num].x - tex_x - 1;

		y = draw_start.y;
		while (y < draw_end.y)
		{
			d = y * 256 - WINDOW_HEIGHT * 128 + line_height * 128;

			tex_y = ((d * env->tex[text_num].y) / line_height) / 256;
			if (env->tex[text_num].y * tex_y + tex_x < env->tex[text_num].y * env->tex[text_num].x && env->tex[text_num].y * tex_y + tex_x > 0)
				colour = env->tex[text_num].data[env->tex[text_num].y * tex_y + tex_x];
			if (side == 1)
				colour = (colour >> 1) & 8355711;
			pixel_put_image(&env->img, colour, x, y);
			y++;
		}
		y = draw_end.y;
		while (y < WINDOW_HEIGHT)
		{
			pixel_put_image(&env->img, rgbtoi(30,10,15), x, y);
			y++;
		}
		
		x++;
	}
	
	put_image(env, &env->img);

	char *str;
	str = ft_itoa(1 / env->delta_time);
	mlx_string_put(env->mlx_ptr, env->win_ptr,10,5, 0xffffff,"FPS: ");
	mlx_string_put(env->mlx_ptr, env->win_ptr,50,5, 0xffffff,str);
	free(str);

	if (env->keys[257])
		move_speed =  10 * env->delta_time;
	else
		move_speed =  5 * env->delta_time;
	rot_speed =  3 * env->delta_time;

	if (env->keys[13])
	{
		if (!env->map[(int)((env->pos.x + env->dir.x * move_speed*1.8))][(int)env->pos.y])
		{

			env->pos.x += (env->dir.x) * move_speed;
		}
		if (!env->map[(int)env->pos.x][(int)((env->pos.y + env->dir.y * move_speed*1.8))])
			env->pos.y += env->dir.y * move_speed;
	}

	if (env->keys[1])
	{
		if (!env->map[(int)(env->pos.x - env->dir.x * move_speed)][(int)env->pos.y])
			env->pos.x -= env->dir.x * move_speed;
		if (!env->map[(int)env->pos.x][(int)(env->pos.y - env->dir.y * move_speed)])
			env->pos.y -= env->dir.y * move_speed;
	}

	if (env->keys[2])
	{
		old_dir_x = env->dir.x;
		env->dir.x = env->dir.x * cos(-rot_speed) - env->dir.y * sin(-rot_speed);
		env->dir.y = old_dir_x * sin(-rot_speed) + env->dir.y * cos(-rot_speed);
		old_plane_x = env->plane.x;
		env->plane.x = env->plane.x * cos(-rot_speed) - env->plane.y * sin(-rot_speed);
		env->plane.y = old_plane_x * sin(-rot_speed) + env->plane.y * cos(-rot_speed);
	}
	
	if (env->keys[0])
	{
		old_dir_x = env->dir.x;
		env->dir.x = env->dir.x * cos(rot_speed) - env->dir.y * sin(rot_speed);
		env->dir.y = old_dir_x * sin(rot_speed) + env->dir.y * cos(rot_speed);
		old_plane_x = env->plane.x;
		env->plane.x = env->plane.x * cos(rot_speed) - env->plane.y * sin(rot_speed);
		env->plane.y = old_plane_x * sin(rot_speed) + env->plane.y * cos(rot_speed);
	}
	return (0);
}

/*
**All of the hooks
*/

void		handle_hooks(void *win_ptr, t_environment *env)
{
	mlx_hook(win_ptr, 2, 0L, key_down, env);
	mlx_hook(win_ptr, 3, 0L, key_release, env);
	mlx_hook(win_ptr, 17, 0L, finish, env);
	mlx_loop_hook(env->mlx_ptr, fun, env);
}
