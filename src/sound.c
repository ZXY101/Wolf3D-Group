/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stenner <stenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:10:46 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 12:53:15 by stenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	sdl_audio_init(void)
{
	SDL_Init(SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_error("Could not open audio device!");
}

void	play_audio_effect(t_menu *menu, char *wav)
{
	menu->audio.wave = Mix_LoadWAV(wav);
	if (menu->audio.wave == NULL)
		ft_error("Could not load wav file!");
	if (Mix_PlayChannel(1, menu->audio.wave, 0) == -1)
		ft_error("could not play wave");
	Mix_FreeChunk(menu->audio.wave);
}

void	play_music(t_menu *menu, char *wav)
{
	if (!Mix_PlayingMusic())
	{
		menu->audio.music = Mix_LoadMUS(wav);
		if (!menu->audio.music)
			ft_error("Could not load music");
		if (Mix_PlayMusic(menu->audio.music, -1) == -1)
			ft_error("Could not play music");
	}
}
