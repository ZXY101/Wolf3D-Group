/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:31:38 by stenner           #+#    #+#             */
/*   Updated: 2019/07/30 12:43:41 by stenner          ###   ########.fr       */
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
	int y;

	y = env->rd.draw_end.y;
	while (y < WINDOW_HEIGHT)
	{
		pixel_put_image(&env->img, rgbtoi(30,10,15), x, y);
		y++;
	}
}
