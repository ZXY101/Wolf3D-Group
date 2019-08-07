/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:50:17 by stenner           #+#    #+#             */
/*   Updated: 2019/08/07 10:03:59 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_init_tex(t_environment *env)
{
	env->tex[0].name = "textures/hmmm.xpm";
	env->tex[1].name = "textures/left.xpm";
	env->tex[2].name = "textures/right.xpm";
	env->tex[3].name = "textures/greystone.xpm";
	env->tex[4].name = "textures/water.xpm";
	env->tex[5].name = "textures/mossy.xpm";
	env->tex[6].name = "textures/wood.xpm";
	env->tex[7].name = "textures/colorstone.xpm";
	env->tex[8].name = "textures/bluestone.xpm";
	env->tex[9].name = "textures/eagle.xpm";
}

void	ft_validate_tex(t_environment *env)
{
	int		i;
	char	*str;

	i = 0;
	while (i < TEXMAX)
	{
		if (open(env->tex[i].name, O_RDONLY) < 0)
		{
			str = ft_strjoin_free("Texture ", ft_itoa(i + 1), 0, 1);
			str = ft_strjoin_free(str, " Could not be Loaded!", 1, 0);
			ft_error(str);
		}
		i++;
	}
}

void	ft_load_tex(t_environment *env)
{
	int i;

	i = 0;
	while (i < TEXMAX)
	{
		env->tex[i].img = mlx_xpm_file_to_image(env->mlx_ptr,
		env->tex[i].name, &env->tex[i].x, &env->tex[i].y);
		env->tex[i].data = (int*)mlx_get_data_addr(env->tex[i].img,
		&env->tex[i].b,
		&env->tex[i].b,
		&env->tex[i].b);
		i++;
	}
}

void	calc_textures(t_environment *env)
{
	env->td.text_num = env->map[env->rd.map_x][env->rd.map_y] - 1;
	if (env->rd.side == 0)
		env->td.wall_x = env->pos.y + env->rd.pwd * env->rd.ray_dir.y;
	else
		env->td.wall_x = env->pos.x + env->rd.pwd * env->rd.ray_dir.x;
	env->td.wall_x -= floor((env->td.wall_x));
	env->td.tex_x = (int)(env->td.wall_x *
	(double)(env->tex[env->td.text_num].x));
	if (env->rd.side == 0 && env->rd.ray_dir.x > 0)
		env->td.tex_x = env->tex[env->td.text_num].x - env->td.tex_x - 1;
	if (env->rd.side == 1 && env->rd.ray_dir.y < 0)
		env->td.tex_x = env->tex[env->td.text_num].x - env->td.tex_x - 1;
}
