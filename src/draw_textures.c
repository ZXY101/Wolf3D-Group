/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:31:38 by stenner           #+#    #+#             */
/*   Updated: 2019/08/05 13:16:15 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		draw_walls(t_environment *env, int x)
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

static void	calc_wd(t_environment *env)
{
	if (env->rd.side == 0 && env->rd.ray_dir.x > 0)
	{
		env->td.fw.x = env->rd.map_x;
		env->td.fw.y = env->rd.map_y + env->td.wall_x;
	}
	else if (env->rd.side == 0 && env->rd.ray_dir.x < 0)
	{
		env->td.fw.x = env->rd.map_x + 1;
		env->td.fw.y = env->rd.map_y + env->td.wall_x;
	}
	else if (env->rd.side == 1 && env->rd.ray_dir.y > 0)
	{
		env->td.fw.x = env->rd.map_x + env->td.wall_x;
		env->td.fw.y = env->rd.map_y;
	}
	else
	{
		env->td.fw.x = env->rd.map_x + env->td.wall_x;
		env->td.fw.y = env->rd.map_y + 1;
	}
}

void		draw_floor(t_environment *env, int x)
{
	t_floor_data fd;

	calc_wd(env);
	fd.dist_wall = env->rd.pwd;
	fd.dist_player = 0;
	if (env->rd.draw_end.y < 0)
		env->rd.draw_end.y = WINDOW_HEIGHT;
	fd.y = env->rd.draw_end.y + 1;
	while (fd.y < WINDOW_HEIGHT)
	{
		fd.cd = WINDOW_HEIGHT / (2.0 * fd.y - WINDOW_HEIGHT);
		fd.weight = (fd.cd - fd.dist_player) / (fd.dist_wall - fd.dist_player);
		fd.cf.x = fd.weight * env->td.fw.x + (1 - fd.weight) * env->pos.x;
		fd.cf.y = fd.weight * env->td.fw.y + (1 - fd.weight) * env->pos.y;
		fd.ft_x = (int)(fd.cf.x * env->tex[3].x) % env->tex[3].x;
		fd.ft_y = (int)(fd.cf.y * env->tex[3].y) % env->tex[3].y;
		fd.colour = (env->tex[3].data[env->tex[3].x * fd.ft_y + fd.ft_x]
		>> 1) & 8355711;
		fd.colour2 = (env->tex[6].data[env->tex[6].x * fd.ft_y + fd.ft_x]);
		pixel_put_image(&env->img, fd.colour, x, fd.y);
		pixel_put_image(&env->img, fd.colour2, x, WINDOW_HEIGHT - fd.y);
		fd.y++;
	}
}
