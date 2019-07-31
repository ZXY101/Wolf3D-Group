/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:44:52 by stenner           #+#    #+#             */
/*   Updated: 2019/07/31 12:32:26 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WINDOW_LENGTH 640
# define WINDOW_HEIGHT 480
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define TEXMAX	10
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define FILL_RGB(RGB, R, G, B) RGB.r = R, RGB.g = G, RGB.b = B
# include <libft.h>
# include <libvec.h>
# include <mlx.h>
# include <sys/time.h>
//del me
#include <stdio.h>

typedef struct		s_ray_data
{
	t_vector 		camera;
	t_vector 		ray_dir;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			ddx;
	double			ddy;
	double			pwd;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	t_vector		draw_start;
	t_vector		draw_end;
}					t_ray_data;

typedef struct		s_tex_data
{
	int				text_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	int				d;
	unsigned int	colour;
}					t_tex_data;

typedef struct		s_texture
{
	void			*img;
	int				*data;
	int				b;
	int				x;
	int				y;
	char			*name;
}					t_texture;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_line_math
{
	int				delta_x;
	int				delta_y;
	double			grad;
	double			q;
	double			iq;
}					t_line_math;

typedef struct		s_mlx_image
{
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	char			*raw_data;
	int				width;
	int				height;
	t_vector		pos;
}					t_mlx_image;

typedef struct timeval t_timeval;

typedef struct		s_environment
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx_image		img;
	t_vector		pos;
	t_vector		dir;
	t_vector		plane;
	int				keys[512000];
	t_timeval		old_time;
	double			dt;
	t_texture		tex[TEXMAX];
	int				**map;
	double			move_speed;
	double			rot_speed;
	t_ray_data		rd;
	t_tex_data		td;
}					t_environment;

/*
**Utility
*/

int					rgbtoi(int r, int g, int b);
t_vector			ndc_to_screen_space(t_vector coord);
void				draw_line(t_vector c1, t_vector c2, t_mlx_image *img, t_rgb rgb);

/*
**Hooks
*/

void				handle_hooks(void *win_ptr, t_environment *env);

/*
**Keys
*/

void				movement(t_environment *env);
void				rotation(t_environment *env);

/*
**Images
*/

void				pixel_put_image(t_mlx_image *img, int colour, int x, int y);
void				clear_image(t_mlx_image *img, int colour);
void				init_image(t_environment *env, t_mlx_image *img,
					int width, int height);
void				put_image(t_environment *env, t_mlx_image *img);

/*
**Textures
*/

void				ft_init_tex(t_environment *env);
void				ft_validate_tex(t_environment *env);
void				ft_load_tex(t_environment *env);
void				update_dt(t_environment *env);
void				calc_textures(t_environment *env);
void				draw_walls(t_environment *env, int x);
void				draw_floor(t_environment *env, int x);

/*
**Misc
*/

//Map stuff
t_list		*map_interpreter(const char *path, t_environment *env);
void		  map_int_array(t_list *lst, t_environment *env);

void				init_env(t_environment *env);
void				ft_error(char *str);
void				printf_fps(t_environment *env);

/*
**Render
*/

void				initialise_vars(t_environment *env, int x);
void				calc_step_sd(t_environment *env);
void				exec_dda(t_environment *env);
void				calc_lh_wd(t_environment *env);
#endif
