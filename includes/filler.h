/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:29:44 by ydonse            #+#    #+#             */
/*   Updated: 2020/02/14 16:46:46 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <SDL.h>
# include <SDL_image.h>

# define HEIGHT 1000
# define WIDTH 1500



typedef enum				e_player
{
	p1,
	p2
}							t_player;

typedef struct				s_pos
{
	int						x;
	int						y;
}							t_pos;

typedef struct				s_map
{
	int						x;
	int						y;
	char					*tab;
}							t_map;

typedef struct 				s_sprite
{
	SDL_Texture 			*texture;
	unsigned int			h;
	unsigned int			w;
}							t_sprite;

typedef struct				s_texture {
	Uint32					*content;
	SDL_Texture				*texture;
	Uint32					color_tmp;
}							t_texture;

typedef struct				s_sdl
{
	SDL_Window				*pwindow;
	SDL_Renderer			*prenderer;
	SDL_Event				event;
	t_texture				*visu;
}							t_sdl;

typedef struct  			s_main
{
	t_pos					board;
	t_player				player;
	t_sdl					*sdl;
}							t_main;

int							get_player_nb(t_main *s);
char						*fill_tab();
void						display_visu(t_main *s);

#endif
