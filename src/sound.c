/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:10:46 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 09:14:47 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	sdl_audio_init(void)
{
	if (Mix_OpenAudio(8000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,
	512) == -1)
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
	if (!Mix_PlayingMusic() && menu->run == 1)
	{
		menu->audio.music = Mix_LoadMUS(wav);
		if (!menu->audio.music)
			ft_error("Could not load music");
		if (Mix_PlayMusic(menu->audio.music, -1) == -1)
			ft_error("Could not play music");
	}
}
