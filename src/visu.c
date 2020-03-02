/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:21:15 by ydonse            #+#    #+#             */
/*   Updated: 2020/03/02 15:07:27 by ydonse           ###   ########.fr       */
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

SDL_Surface *get_player_photo(char *name)
{
	SDL_Surface	*tmp;
	char		*full_path;
	char		*initial_path;
	char		*year;
	int			i_year;

	i_year = 2013;
	tmp = NULL;
	initial_path = ft_strdup("/sgoinfre/photos_students/");
	while (tmp == NULL && i_year < 2025)
	{
		year = ft_itoa(i_year);
		full_path = ft_strjoin(initial_path, year);
		full_path = ft_strjoin(full_path, "/");
		full_path = ft_strjoin(full_path, name);
		full_path = ft_strjoin(full_path, ".JPG");
		tmp = IMG_Load(full_path);
		i_year++;
	}
	return (tmp);
}

void	init_visu(t_main *s)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit (-1);
	if (!(s->sdl = (t_sdl*)malloc(sizeof(t_sdl))))
		return ;
	if (!(s->sdl->pwindow = SDL_CreateWindow("Filler", 100,
					100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		exit (-1);
	if (!(s->sdl->prenderer = SDL_CreateRenderer(s->sdl->pwindow, -1, 0)))
		exit (-1);
	// if (!(sdl->map = initialize_texture(sdl, WIDTH, HEIGHT)))
	// 	exit (-1);
}

t_sprite *load_sprite(char *path, SDL_Renderer *renderer, SDL_Color *key, int player)
{
	t_sprite	*sprite;
	SDL_Surface	*tmp;

	// tmp = IMG_Load(path);
	if (player)
		tmp = get_player_photo(path);
	else
		tmp = IMG_Load(path);
	if (!(sprite = (t_sprite*)malloc(sizeof(t_sprite))))
		return (NULL);
	ft_bzero((void*)sprite,sizeof(t_sprite));
	if (tmp)
		printf("inage loaded\n");
	if (tmp)
	{
		sprite->w = tmp->w;
		sprite->h = tmp->h;
		sprite->texture = SDL_CreateTextureFromSurface(renderer, tmp);
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

void display_sprite(SDL_Renderer *renderer, t_sprite *sprite, t_pos pos, t_pos size)
{
	SDL_Rect dst;

	dst.x = pos.x;
	dst.y = pos.y;
	dst.w  = size.x;
	dst.h = size.y;
	SDL_RenderCopy(renderer, sprite->texture, NULL, &dst);

}

// char	*fill_tab()
// {
// 	char	*line;
// 	char	*tab;
// 	int		i;
//
// 	i = 0;
// 	tab = ft_strdup("");
// 	line = NULL;
// 	while (get_next_line(0, &line) > 0)
// 	{
// 		// tab = ft_strjoin_free(&tab, &line);
// 		// ft_putstr(tab);
// 		ft_putstr(line);
// 		i++;
// 	}
// 	return (tab);
// }

// char	*fill_tab()
// {
// 	char	buffer[100];
// 	char	*tab;
// 	int		i;
//
// 	i = 0;
// 	tab = ft_strdup("");
// 	read(1, buffer, 99);
// 	// while (read(1, buffer, 9) )
// 	// {
// 	// 	// buffer[9] = '\n';
// 	// 	// ft_putstr(buffer);
// 	// 	ft_putnbr(i);
// 	// 	i++;
// 	// }
// 	ft_putstr("end\n");
// 	return (tab);
// }

void	test_file()
{
	// char *line;
	char	buffer[100];
	// int	 fd;
	FILE *fichier;

	// fd = open("test.test", O_RDWR);
	fichier = fopen("test.txt", "a+");
	while (read(1, &buffer, 99) > 0)
	{
		fprintf(fichier, "%s", buffer);
	}
	fclose(fichier);
	printf("end\n");
}

void	display_visu(t_main *s)
{
	SDL_Event 	event;
	int			continuer;
	t_sprite	*j1;
	t_sprite	*background;
	t_sprite	*j2;
	char		*test = "jgehin";
	char		*test2 = "fmerding";
	t_pos		pos;
	t_pos		size;

	continuer = 1;
	pos.x = 0;
	pos.y = 0;
	// j1 = IMG_Load("/sgoinfre/photos_students/2018/ydonse.jpg");

	// SDL_BlitSurface(j1, NULL, NULL, &pos);
	init_visu(s);
	// fill_tab();
	test_file();

	j1 = NULL;
	background = NULL;
	// j1 = load_sprite("/sgoinfre/photos_students/2018/ydonse.JPG", s->sdl->prenderer, NULL);
	j1 = load_sprite(test, s->sdl->prenderer, NULL, 1);
	j2 = load_sprite(test2, s->sdl->prenderer, NULL, 1);
	background = load_sprite("filler.png", s->sdl->prenderer, NULL, 0);

	// printf("j1->w = %d\n", j1->w);
	size.x = 500;
	size.y = 400;
	pos.x = 44.8 - (500 / 2) + 120;
	pos.y = 320;
	if (j1)
		display_sprite(s->sdl->prenderer, j1, pos, size);
	// else
	// {
	// 	j1 = load_sprite()
	// }
	pos.x = 1203 - (500 / 2) + 120;
	pos.y = 320;
	if (j2)
		display_sprite(s->sdl->prenderer, j2, pos, size);
	pos.x = 0;
	pos.y = 0;
	size.x = background->w;
	size.y = background->h;

	if (background)
		display_sprite(s->sdl->prenderer, background, pos, size);
	SDL_RenderPresent(s->sdl->prenderer);
	while (continuer)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			continuer = 0;
	}
}
