/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:26:45 by stenner           #+#    #+#             */
/*   Updated: 2019/07/29 13:17:07 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**This c file includes all functions needed to draw a line between two points
*/

#include <wolf3d.h>

/*
**Line drawing algorithm for when m < 1
*/

static void	draw_line_lower(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb c)
{
	int			i;
	t_line_math l;

	if (c1.x > c2.x)
		ft_swap(&c1, &c2, sizeof(t_vector));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_y / (double)l.delta_x;
	i = 0;
	while (i < l.delta_x)
	{
		l.q = ((c1.y + i * l.grad) - (int)(c1.y + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(img, rgbtoi(c.r * l.iq, c.g * l.iq, c.b * l.iq)
		, c1.x + i, c1.y + i * l.grad);
		pixel_put_image(img, rgbtoi(c.r * l.q, c.g * l.q, c.b * l.q)
		, c1.x + i, (c1.y + i * l.grad) + 1);
		i++;
	}
}

/*
**Line drawing algorithm for when m > 1
*/

static void	draw_line_upper(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb c)
{
	int			i;
	t_line_math l;

	if (c1.y > c2.y)
		ft_swap(&c1, &c2, sizeof(t_vector));
	l.delta_x = c2.x - c1.x;
	l.delta_y = c2.y - c1.y;
	l.grad = l.delta_x / (double)l.delta_y;
	i = 0;
	while (i < l.delta_y)
	{
		l.q = ((c1.x + i * l.grad) - (int)(c1.x + i * l.grad));
		l.iq = 1 - l.q;
		pixel_put_image(img, rgbtoi(c.r * l.iq, c.g * l.iq, c.b * l.iq)
		, c1.x + i * l.grad, c1.y + i);
		pixel_put_image(img, rgbtoi(c.r * l.q, c.g * l.q, c.b * l.q),
		(c1.x + i * l.grad) + 1, c1.y + i);
		i++;
	}
}

/*
**Check to see which algorithm to use
*/

void		draw_line(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb rgb)
{
	int			delta_x;
	int			delta_y;

	delta_x = c2.x - c1.x;
	delta_y = c2.y - c1.y;
	if (abs(delta_x) < abs(delta_y))
		draw_line_upper(c1, c2, img, rgb);
	else
		draw_line_lower(c1, c2, img, rgb);
}
