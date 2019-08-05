/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:00:38 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 07:37:50 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			sdl_init(t_menu *menu)
{
	menu->cur = 0;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	menu->win = SDL_CreateWindow("MENU", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WINDOW_LENGTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (!menu->win)
		ft_error("Window couldn't init!");
	menu->render = SDL_CreateRenderer(menu->win, -1, 0);
	if (!menu->render)
		ft_error("Renderer cried on his way home!");
	sdl_font_init(menu);
	sdl_audio_init();
}

void			sdl_exit(t_menu *menu)
{
	SDL_DestroyTexture(menu->img);
	SDL_DestroyRenderer(menu->render);
	Mix_FreeMusic(menu->audio.music);
	Mix_CloseAudio();
	TTF_CloseFont(menu->font);
	SDL_DestroyWindow(menu->win);
	SDL_Quit();
	(void)menu;
}

void			menu_update(t_menu *menu, int pos_x, int pos_y ,int width, int height)
{
	int			i;
	SDL_Color	colo;
	i = 0;
	
	menu->msg[0].txt = "Start";
	menu->msg[1].txt = "Exit";

	while (i < MENU_ITEMS)
	{
		if (i == menu->cur)
			colo = menu->selected;
		else
			colo = menu->deselected; 
		menu->msg[i].surf = TTF_RenderText_Solid(menu->font, menu->msg[i].txt,
		colo);
		menu->msg[i].msg = SDL_CreateTextureFromSurface(menu->render, menu->msg[i].surf);
		menu->msg[i].rect.x = pos_x;
		menu->msg[i].rect.y = pos_y + (i * height);
		menu->msg[i].rect.w = width;
		menu->msg[i].rect.h = height;
		SDL_RenderCopy(menu->render, menu->msg[i].msg, NULL, &menu->msg[i].rect);
		SDL_DestroyTexture(menu->msg[i].msg);
		SDL_FreeSurface(menu->msg[i].surf);
		i++;
		play_music(menu, "sounds/loop.wav");
	}
}

void	sdl_keyhndl(t_menu *menu)
{
	if (menu->evnt.type == SDL_QUIT || menu->evnt.key.keysym.sym == SDLK_ESCAPE)
		menu->run = 0;
	if (menu->evnt.key.keysym.sym == SDLK_RETURN)
		menu->run = 2;
	if (menu->evnt.type == SDL_KEYDOWN)
	{
		if (menu->evnt.key.keysym.sym == SDLK_w && menu->cur > 0)
			menu->cur--;
		if (menu->evnt.key.keysym.sym == SDLK_s && menu->cur < MENU_ITEMS - 1)
			menu->cur++;
	}
}

void			sdl_update(t_menu *menu)
{

	while (SDL_PollEvent(&menu->evnt))
		sdl_keyhndl(menu);
	SDL_RenderClear(menu->render);
	SDL_RenderCopy(menu->render, menu->img, NULL, NULL);
	menu_update(menu, 50,(int)(WINDOW_HEIGHT /2), 100 ,30);
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
	if (menu.run == 0 || (menu.cur == MENU_ITEMS - 1))
		exit(0);
	return ("maps/lvl0.map");
}