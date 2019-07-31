/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:00:38 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/07/31 19:21:58 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

SDL_Texture		*load_tex(char *filename, SDL_Renderer *render)
{
	SDL_Texture	*tex;
	SDL_Surface	*surf;

	tex = NULL;
	surf = SDL_LoadBMP(filename);
	if (!surf)
		ft_error(ft_strjoin("Couldn't load: ", filename));
	else
	{
		tex = SDL_CreateTextureFromSurface(render, surf);
		if (!tex)
			ft_error(ft_strjoin("Couldn't create texture: ", SDL_GetError()));
	}
	SDL_FreeSurface(surf);
	return (tex);
}

void			sdl_init(t_menu *menu)
{
	SDL_Init(SDL_INIT_VIDEO);
	menu->win = SDL_CreateWindow("MENU", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WINDOW_LENGTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!menu->win)
		ft_error("Window couldn't init!");
	menu->render = SDL_CreateRenderer(menu->win, -1, 0);
	if (!menu->render)
		ft_error("Renderer cried on his way home!");
}

void			sdl_exit(t_menu *menu)
{
	SDL_DestroyWindow(menu->win);
	SDL_DestroyTexture(menu->img);
	SDL_DestroyRenderer(menu->render);
	SDL_Quit();
}

void			sdl_update(t_menu *menu)
{
	while (SDL_PollEvent(&menu->evnt))
	{
		if (menu->evnt.type == SDL_QUIT ||
		menu->evnt.key.keysym.sym == SDLK_ESCAPE)
			menu->run = 0;
		if (menu->evnt.key.keysym.sym == SDLK_RETURN)
		{
			menu->run = 2;
			break ;
		}
	}
	SDL_RenderClear(menu->render);
	SDL_RenderCopy(menu->render, menu->img, NULL, NULL);
	SDL_RenderPresent(menu->render);
}

char			*main_menu(void)
{
	t_menu		menu;

	sdl_init(&menu);
	menu.img = load_tex("./textures/main_menu/main.bmp", menu.render);
	menu.run = 1;
	
	while (menu.run == 1)
		sdl_update(&menu);
	sdl_exit(&menu);
	if (menu.run == 0)
		exit(0);
	return ("maps/lvl0.map");
}
