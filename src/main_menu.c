/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:00:38 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 09:30:58 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		menu_update(t_menu *menu)
{
	int			i;
	SDL_Color	colo;

	i = 0;
	menu->msg[0].txt = "Start";
	menu->msg[1].txt = "Exit";
	while (i < MENU_ITEMS)
	{
		colo = (i == menu->cur) ? menu->selected : menu->deselected;
		menu->msg[i].surf = TTF_RenderText_Solid(menu->font, menu->msg[i].txt,
		colo);
		menu->msg[i].msg = SDL_CreateTextureFromSurface(menu->render,
		menu->msg[i].surf);
		menu->msg[i].rect.x = menu->msg[i].pos_x;
		menu->msg[i].rect.y = menu->msg[i].pos_y + (i * menu->msg[i].height);
		menu->msg[i].rect.w = menu->msg[i].width;
		menu->msg[i].rect.h = menu->msg[i].height;
		SDL_RenderCopy(menu->render, menu->msg[i].msg, NULL,
		&menu->msg[i].rect);
		SDL_DestroyTexture(menu->msg[i].msg);
		SDL_FreeSurface(menu->msg[i].surf);
		i++;
		play_music(menu, "sounds/loop.wav");
	}
}

void		sdl_keyhndl(t_menu *menu)
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

void		sdl_update(t_menu *menu)
{
	while (SDL_PollEvent(&menu->evnt))
		sdl_keyhndl(menu);
	SDL_RenderClear(menu->render);
	SDL_RenderCopy(menu->render, menu->img, NULL, NULL);
	menu->msg[0].pos_x = 50;
	menu->msg[0].pos_y = (int)(WINDOW_HEIGHT / 2);
	menu->msg[0].height = 30;
	menu->msg[0].width = 100;
	menu->msg[1] = menu->msg[0];
	menu_update(menu);
	SDL_RenderPresent(menu->render);
}

char		*main_menu(void)
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
