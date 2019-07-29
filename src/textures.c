/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:50:17 by stenner           #+#    #+#             */
/*   Updated: 2019/07/29 15:45:22 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_init_tex(t_environment *env)
{
	env->tex[0].name = "textures/left.xpm";
	env->tex[1].name = "textures/middle.xpm";
	env->tex[2].name = "textures/right.xpm";
	env->tex[3].name = "textures/hmmm.xpm";
	env->tex[4].name = "textures/wall4.xpm";
	env->tex[5].name = "textures/wall5.xpm";
	env->tex[6].name = "textures/banner.xpm";
	env->tex[7].name = "textures/torch.xpm";
	env->tex[8].name = "textures/wood.xpm";
	env->tex[9].name = "textures/water.xpm";
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
