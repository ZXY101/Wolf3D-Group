/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:45:17 by stenner           #+#    #+#             */
/*   Updated: 2019/07/29 13:17:07 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file contains all neccessary functions pertaining to mlx images
*/

#include <wolf3d.h>

/*
**Places a pixel on the image at the given x & y coordinate
*/

void	pixel_put_image(t_mlx_image *img, int colour, int x, int y)
{
	int *data;

	if (x >= img->width || x < 0)
		return ;
	if (y >= img->height || y < 0)
		return ;
	data = (int*)&img->raw_data[x * 4 + y * img->size_line];
	*data = colour;
}

/*
**Makes every pixel on the image the given colour
*/

void	clear_image(t_mlx_image *img, int colour)
{
	int *data;
	int i;

	data = (int*)img->raw_data;
	i = 0;
	while (i < (img->width * img->height))
	{
		data[i] = colour;
		i++;
	}
}

/*
**Initializes a new image
*/

void	init_image(t_environment *env, t_mlx_image *img, int width, int height)
{
	img->img_ptr = mlx_new_image(env->mlx_ptr, width, height);
	img->raw_data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
	&img->endian);
	img->width = width;
	img->height = height;
	img->pos.x = 0;
	img->pos.y = 0;
	clear_image(img, 0x000000);
}

/*
**Puts the image onto the window
*/

void	put_image(t_environment *env, t_mlx_image *img)
{
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, img->img_ptr,
	img->pos.x, img->pos.y);
}
