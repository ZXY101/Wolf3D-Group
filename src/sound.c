#include <wolf3d.h>

void	audio_init()
{
	
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		ft_error("Auidio Device init Problem");
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_error("could not init Audio mixer");
}


void	audio_set(t_menu *menu)
{
	menu->audio.sound = Mix_LoadMUS("./sounds/loop.mp3");
	if (!Mix_PlayingMusic())
		Mix_PlayMusic(menu->audio.sound , -1);
}

void	audio_free(t_menu *menu)
{
	Mix_FreeMusic(menu->audio.sound);
	Mix_CloseAudio();
	SDL_Quit();
}