/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:31:38 by stenner           #+#    #+#             */
/*   Updated: 2019/07/30 18:50:50 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_walls(t_environment *env, int x)
{
	int y;

	y = env->rd.draw_start.y;
	while (y < env->rd.draw_end.y)
	{
		env->td.d = y * 256 - WINDOW_HEIGHT * 128 + env->rd.line_height * 128;
		env->td.tex_y = ((env->td.d * env->tex[env->td.text_num].y) /
		env->rd.line_height) / 256;
		if (env->tex[env->td.text_num].y * env->td.tex_y +
		env->td.tex_x < env->tex[env->td.text_num].y *
		env->tex[env->td.text_num].x && env->tex[env->td.text_num].y *
		env->td.tex_y + env->td.tex_x > 0)
			env->td.colour = env->tex[env->td.text_num].data
			[env->tex[env->td.text_num].y * env->td.tex_y + env->td.tex_x];
		if (env->rd.side == 1)
			env->td.colour = (env->td.colour >> 1) & 8355711;
		pixel_put_image(&env->img, env->td.colour, x, y);
		y++;
	}
}

void	draw_floor(t_environment *env, int x)
{
	t_vector	floor_wall;

	if (env->rd.side == 0 && env->rd.ray_dir.x> 0)
	{
		floor_wall.x = env->rd.map_x;
		floor_wall.y = env->rd.map_y + env->td.wall_x;
	}
	else if (env->rd.side == 0 && env->rd.ray_dir.x < 0)
	{
		floor_wall.x = env->rd.map_x + 1;
		floor_wall.y = env->rd.map_y + env->td.wall_x;
	}
	else if (env->rd.side == 1 && env->rd.ray_dir.y > 0)
	{
		floor_wall.x = env->rd.map_x + env->td.wall_x;
		floor_wall.y = env->rd.map_y;
	}
	else
	{
		floor_wall.x = env->rd.map_x + env->td.wall_x;
		floor_wall.y = env->rd.map_y + 1;
	}

	int			y;
	double dist_wall;
	double dist_player;
	double current_dist;
	double weight;
	t_vector current_floor;
	int floor_tex_x;
	int floor_tex_y;
	int colour;
	dist_wall = env->rd.pwd;
	dist_player = 0;
	if (env->rd.draw_end.y < 0)
		env->rd.draw_end.y = WINDOW_HEIGHT;
	y = env->rd.draw_end.y + 1;
	while (y < WINDOW_HEIGHT)
	{
		current_dist = WINDOW_HEIGHT / (2 * y - WINDOW_HEIGHT);
		weight = (current_dist - dist_player) / (dist_wall - dist_player);

		current_floor.x = weight * floor_wall.x + (1 - weight) * env->pos.x;
		current_floor.y = weight * floor_wall.y + (1 - weight) * env->pos.y;

		floor_tex_x = (int)(current_floor.x * env->tex[6].x) % env->tex[6].x;
		floor_tex_y = (int)(current_floor.y * env->tex[6].y) % env->tex[6].y;

		colour	= (env->tex[3].data[env->tex[3].x * floor_tex_y + floor_tex_x]
		>> 1) & 8355711;

		pixel_put_image(&env->img, colour, x, y);
		pixel_put_image(&env->img, colour,x , WINDOW_HEIGHT - y);
		y++;
	}

}
