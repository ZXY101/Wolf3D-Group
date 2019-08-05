/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:16:25 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 09:17:35 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		sdl_init(t_menu *menu)
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

void		sdl_exit(t_menu *menu)
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
