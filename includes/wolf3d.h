/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:52 by stenner           #+#    #+#             */
/*   Updated: 2019/07/30 20:01:02 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WINDOW_LENGTH 640
# define WINDOW_HEIGHT 480
# define TEXMAX	10
# define FILL_RGB(RGB, R, G, B) RGB.r = R, RGB.g = G, RGB.b = B
# include <SDL2/SDL.h>
# include <libft.h>
# include <libvec.h>
# include <mlx.h>
# include <sys/time.h>

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
typedef struct	s_texture
{
	void		*img;
	int			*data;
	int			b;
	int			x;
	int			y;
	char		*name;
}				t_texture;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_line_math
{
	int			delta_x;
	int			delta_y;
	double		grad;
	double		q;
	double		iq;
}				t_line_math;

typedef struct	s_mlx_image
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*raw_data;
	int			width;
	int			height;
	t_vector	pos;
}				t_mlx_image;

typedef struct 	timeval t_timeval;

typedef struct	s_environment
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_image	img;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	int			keys[512000];
	t_timeval	old_time;
	double		delta_time;
	t_texture	tex[TEXMAX];
}				t_environment;


int				key_down(int key, t_environment *env);

/*
**Utility
*/

int				rgbtoi(int r, int g, int b);
t_vector		ndc_to_screen_space(t_vector coord);
void			draw_line(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb rgb);

/*
**Hooks
*/

void			handle_hooks(void *win_ptr, t_environment *env);

/*
**Images
*/

void			pixel_put_image(t_mlx_image *img, int colour, int x, int y);
void			clear_image(t_mlx_image *img, int colour);
void			init_image(t_environment *env, t_mlx_image *img,
				int width, int height);
void			put_image(t_environment *env, t_mlx_image *img);

/*
**Textures
*/
void			ft_init_tex(t_environment *env);
void			ft_validate_tex(t_environment *env);
void			ft_load_tex(t_environment *env);

/*
**Main_Menu And SDL (sound)
*/
char			*main_menu();
#endif
