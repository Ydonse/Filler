/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:21:15 by ydonse            #+#    #+#             */
/*   Updated: 2020/02/14 17:19:39 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	update_image(t_main *s, t_texture *texture)
{
	SDL_SetRenderTarget(s->sdl->prenderer, texture->texture);
	SDL_UpdateTexture(texture->texture, NULL, texture->content, WIDTH
		* sizeof(Uint32));
	SDL_SetRenderTarget(s->sdl->prenderer, NULL);
	SDL_RenderCopy(s->sdl->prenderer, texture->texture, NULL, NULL);
	SDL_RenderPresent(s->sdl->prenderer);
}

void	init_visu(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit (-1);
	if (!(sdl = (t_sdl*)malloc(sizeof(t_sdl))))
		return ;
	if (!(sdl->pwindow = SDL_CreateWindow("Filler", 100,
					100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		exit (-1);
	if (!(sdl->prenderer = SDL_CreateRenderer(sdl->pwindow, -1, 0)))
		exit (-1);
	// if (!(sdl->map = initialize_texture(sdl, WIDTH, HEIGHT)))
	// 	exit (-1);
}

t_sprite *load_sprite(char *path, SDL_Renderer *renderer, SDL_Color *key)
{
	t_sprite	*sprite;
	SDL_Surface	*tmp;

	tmp = IMG_Load(path);
	if (!(sprite = (t_sprite*)malloc(sizeof(t_sprite))))
		return (NULL);
	ft_bzero((void*)sprite,sizeof(t_sprite));
	if (tmp)
		printf("inage loaded\n");
	if (tmp)
	{
		printf("oui ?\n");
		sprite->texture = SDL_CreateTextureFromSurface(renderer, tmp);
		printf("non ?\n");
		if (sprite->texture)
		printf("yes\n");
		ft_memdel((void**)&tmp);
	}
	else
		return(NULL);
	return (sprite);
}

t_sprite *free_sprite(t_sprite *sprite)
{
	if (sprite)
	{
		SDL_DestroyTexture(sprite->texture);
		free(sprite);
	}
	return (NULL);
}

void display_sprite(SDL_Renderer *renderer, t_sprite *sprite, int x, int y)
{
	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w  = sprite->w;
	dst.h = sprite->h;
	SDL_RenderCopy(renderer, sprite->texture, NULL, &dst);

}

void	display_visu(t_main *s)
{
	SDL_Event 	event;
	int			continuer;
	SDL_Rect	pos;
	t_sprite	*sprite;

	continuer = 1;
	pos.x = 0;
	pos.y = 0;
	// j1 = IMG_Load("/sgoinfre/photos_students/2018/ydonse.jpg");

	// SDL_BlitSurface(j1, NULL, NULL, &pos);
	init_visu(s->sdl);
	sprite = NULL;
	sprite = load_sprite("/sgoinfre/photos_students/2018/ydonse.JPG", s->sdl->prenderer, NULL);
	if (sprite)
		display_sprite(s->sdl->prenderer, sprite, 50, 50);
	else
		ft_putstr("nop\n");
	SDL_RenderPresent(s->sdl->prenderer);
	while (continuer)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			continuer = 0;
	}
}
