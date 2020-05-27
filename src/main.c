/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:26:55 by ydonse            #+#    #+#             */
/*   Updated: 2020/03/06 15:22:15 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdlib.h>

void	display_tab(t_main *s, FILE *fichier, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		fprintf(fichier, "%s\n", tab[i++]);
}

int		test_piece(t_main *s, int i, int j, FILE *fichier)
{
	int k;
	t_pos coord;

	k = 1;
	while (s->new_piece.index[k] != 0)
	{
		coord.y = i - s->new_piece.coord[k].y;
		coord.x = j - s->new_piece.coord[k].x;
		// fprintf(fichier, "%d %d\n", s->new_piece.coord[k].y, s->new_piece.coord[k].x);
		// fprintf(fichier, "%c\n", s->map[coord.y][coord.x]);
		if (!(coord.y >= 0 && coord.y <= s->size_y && coord.x >= 0
			&& coord.x <= s->size_x && s->map[coord.y][coord.x] == '.'))
			return (0);
		k++;
	}
	return (1);
}

void	set_piece(t_main *s)
{
	int i;
	int	j;
	char *tosend;
	FILE *fichier;

	fichier = fopen("test.txt", "a+");
	i = 0;
	// fprintf(fichier, "here\n");
	if (!s->map)
	{
		// fprintf(fichier, "error\n");
		exit(-1);
	}
	while(s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'o' || s->map[i][j] == 'O')
			{
				// fprintf(fichier, "here\n");
				if (test_piece(s, i, j, fichier))
				{
					// fprintf(fichier, "here\n");
					// display_tab(s, fichier, s->map);
					// display_tab(s, fichier, s->piece);
					// fprintf(fichier, "Je veux le mettre en  %d %d\n", i, j);
					tosend = ft_strjoin(ft_itoa(i - s->def.y), " ");
					tosend = ft_strjoin(tosend, ft_itoa(j - s->def.x));
					tosend = ft_strjoin(tosend, "\n");
					// fprintf(fichier, "renvoie %s\n", tosend);
					write(STDOUT_FILENO, tosend, ft_strlen(tosend));
					ft_strdel(&tosend);
					break ;
				}
			}
			j++;
		}
		i++;
	}
	fclose (fichier);
}

void	test_map(t_main *s)
{
	FILE *fichier;
	int i;

	i = 0;
	fichier = fopen("test.txt", "a+");
	while (s->map[i])
		fprintf(fichier, "%s\n", s->map[i++]);
	// set_piece(s, fichier);
	fclose(fichier);
}

int	main(int argc, char **argv)
{
	t_main 		*s;
	static int	player = 0;
	FILE 		*fichier;
	int			i;

	i = 0;
	fichier = fopen("test.txt", "a+");
	// ft_bzero((void **)&s, sizeof(t_main));
	if (!(s = (t_main*)malloc(sizeof(t_main))))
		return (0);
	ft_bzero((void*)s, sizeof(t_main));
	// s->fd = open("temp.txt", O_RDONLY);
	s->fd = STDIN_FILENO;

	while (get_next_line(s->fd, &(s->line)) > 0)
	{
		// fprintf(fichier, "s->line = %s\n", s->line);
		if (fill_map(s, &player, fichier, s->i) == 1)
		{
			set_piece(s);
			free_map(s);
			s->first = 1;
			s->i = 0;
		}
		ft_memdel((void **)(&(s->line)));
		ft_strdel(&(s->line));
	}
		// test_piecette(s);



	// test_piecette(s);
	// test_map(s);
	// //s.board = get_board_size(&s);
	// // while (1)
	// // {
	// // 	//get_piece
	// // 	//place_piece
	// // 	//return_piece_pos
	// // }
	// ft_putstr(tab);
	// write(1, tab, ft_strlen(tab));
	//
	// // ft_putstr(tab);
	return(0);
}
