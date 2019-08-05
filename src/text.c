/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:21:47 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/05 09:10:25 by rcoetzer         ###   ########.fr       */
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

void			sdl_font_init(t_menu *menu)
{
	TTF_Init();
	menu->font = TTF_OpenFont("./fonts/Menu.ttf", 20);
	FILL_RGB(menu->selected, 255, 230, 230);
	FILL_RGB(menu->deselected, 255, 0, 0);
	menu->deselected.a = 80;
	menu->selected.a = 255;
}
