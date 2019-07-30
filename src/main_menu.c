/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:00:38 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/30 20:07:50 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

typedef struct s_menu
{
	SDL_Window		*win;
	SDL_Texture		*img;
	SDL_Renderer	*render;
	SDL_Rect		rec;
	SDL_Texture		*sprite;
	SDL_Event		evnt;
	int				run;
}			   t_menu;

SDL_Texture		*load_tex(char *filename, SDL_Renderer *render)
{
	SDL_Texture	*tex;
	SDL_Surface	*surf;
	
	tex = NULL;
	surf = NULL;
	surf = SDL_LoadBMP(filename);
	if (!surf)
		ft_putendl(ft_strjoin("Couldn't load: ", filename));	//ft_error
	else
	{
		tex = SDL_CreateTextureFromSurface(render, surf);
		if (!tex)
			ft_putendl(ft_strjoin("Couldn't create texture: ",  SDL_GetError())); //ft_error
	}
	SDL_FreeSurface(surf);
	return (tex);	
}

char	*main_menu()
{
	t_menu	menu;

	SDL_Init(SDL_INIT_VIDEO);
	menu.win = SDL_CreateWindow("MENU!",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WINDOW_LENGTH ,WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!menu.win)
		ft_putendl("Window couldn't init!"); /*ft_error */	
	menu.render = SDL_CreateRenderer(menu.win, -1, 0);
	if (!menu.render)
		ft_putendl("Renderer cried on his way home!"); /*ft_eror */
	menu.img = load_tex("./textures/main_menu/main.bmp", menu.render);
	menu.run = 1;
	while (menu.run == 1)
	{
		while(SDL_PollEvent(&menu.evnt) != 0)
		{
			if (menu.evnt.type == SDL_QUIT || menu.evnt.key.keysym.sym == SDLK_ESCAPE)
				menu.run = 0;
			if (menu.evnt.key.keysym.sym == SDLK_RETURN)
				{
					menu.run = 2;
					break ;
				}
		}
		SDL_RenderClear(menu.render);
		SDL_RenderCopy(menu.render, menu.img, NULL, NULL);
		SDL_RenderPresent(menu.render);
	}
	SDL_DestroyWindow(menu.win);
	SDL_DestroyTexture(menu.img);
	SDL_DestroyRenderer(menu.render);
	SDL_Quit();
	if (menu.run == 0)
		exit(0);
	return ("maps/lvl0.map");
}