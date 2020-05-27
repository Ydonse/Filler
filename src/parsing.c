/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:21:22 by ydonse            #+#    #+#             */
/*   Updated: 2020/03/06 15:21:37 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player_nb(char *line)
{
	if(strstr(line, "ydonse") && strstr(line, "p1"))
		return (1);
	else
		return (2);
}

void	free_map(t_main *s)
{
	ft_free_tab_str(&(s->map));
	ft_free_tab_str(&(s->piece));
	ft_memdel((void **)&s->new_piece.index);
	ft_memdel((void **)&s->new_piece.coord);

}

// char	**cut_tab(char *line)
// {
// 	int		x;
// 	int		y;
// 	char	**map;
// 	char	**split;
//
//
//
// 	return (map);
// }
void	fill_new_piece(t_main *s, FILE *fichier)
{
	int	i;
	int	j;
	int	k;
	int		boo;

	i = 0;
	k = 0;
	boo = 0;
	s->new_piece.coord[0].x = 0;
	s->new_piece.coord[0].y = 0;
	while (s->piece[i])
	{
		j = 0;
		while(s->piece[i][j])
		{
			if (s->piece[i][j] && s->piece[i][j] != '.')
			{
				if (!boo)
				{
					s->def.x = j;
					s->def.y = i;
					boo = 1;
				}
				else
				{
					display_tab(s, fichier, s->piece);
					// fprintf(fichier, "j = %d, i = %d, def.x = %d, def.y = %d\n", j, i, s->def.x, s->def.y);
					if (s->def.x >= j)
						s->new_piece.coord[k].x = s->def.x - j;
					else
						s->new_piece.coord[k].x = j - s->def.x;
					s->new_piece.coord[k].y = i - s->def.y;
					fprintf(fichier, "case[%d] = y(%d) x(%d)\n", k, s->new_piece.coord[k].y, s->new_piece.coord[k].x);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
void	transform_piece(t_main *s, FILE *fichier)
{
	int	i;
	int	j;
	int	cmpt;

	i = 0;
	cmpt = 0;
	// fprintf(fichier, "transform piece\n");
	while (s->piece[i])
	{
		// fprintf(fichier, "s->piece[%d] = %s\n",i,  s->piece[i]);
		j = 0;
		while(s->piece[i][j])
		{
			if (s->piece[i][j] && s->piece[i][j] != '.')
				cmpt++;
			j++;
		}
		i++;
	}
	i = 0;
	if (!(s->new_piece.index = malloc(sizeof(int) * (cmpt + 1))))
		return ;
	if (!(s->new_piece.coord = malloc(sizeof(t_pos) * (cmpt + 1))))
		return ;
	ft_bzero((void *)s->new_piece.index, sizeof(int) * (cmpt + 1));
	ft_bzero((void *)s->new_piece.coord, sizeof(t_pos) * (cmpt + 1));
	// fprintf(fichier, "nb de cases = %d\n", cmpt);
	while(i < cmpt)
	{
		s->new_piece.index[i] = i + 1;
		i++;
	}
	fill_new_piece(s, fichier);
}

void	get_piece(t_main *s, FILE *fichier, int fd)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(s->line, ' ');
	// ft_memdel((void **)&line);
	if (s->piece)
		ft_free_tab_str(&(s->piece));
	// fprintf(fichier, "%s\n", split[1]);
	s->x_piece = ft_atoi(split[2]);
	s->y_piece = ft_atoi(split[1]);
	if (!(s->piece = malloc(sizeof(char *) * (s->y_piece + 1))))
		return ;
	ft_bzero((void *)s->piece, sizeof(char *) * (s->y_piece + 1));
	ft_free_tab_str(&split);
	while (i < s->y_piece)
	{
		get_next_line(fd, &(s->line));
		// fprintf(fichier, "s->line = %s\n", s->line);
		if (s->line[0] == '.' || s->line[0] == '*')
		{
			// fprintf(fichier, "line = %s\n", line);
			s->piece[i] = ft_strdup(s->line);
			// fprintf(fichier, "%s\n", s->piece[i]);
			i++;
		}
		ft_memdel((void **)(&(s->line)));
		// ft_strdel(&s->line);
	}
	// fprintf(fichier, "s->piece[0] = %s\n", s->piece[0]);
	transform_piece(s, fichier);
}
// void	get_piece(t_main *s, FILE *fichier, char *line, int fd)
// {
// 	int		i;
// 	char	**split;
//
// 	i = 0;
// 	split = ft_strsplit(line, ' ');
// 	// ft_memdel((void **)&line);
// 	if (s->piece)
// 		ft_free_tab_str(s->piece);
// 	fprintf(fichier, "%s\n", split[1]);
// 	s->x_piece = ft_atoi(split[2]);
// 	s->y_piece = ft_atoi(split[1]);
// 	if (!(s->piece = ft_memalloc(sizeof(char *) * (s->y_piece + 1))))
// 		return ;
// 	ft_free_tab_str(split);
// 	while (i < s->y_piece)
// 	{
// 		get_next_line(fd, &line);
// 		if (line[0] == '.' || line[0] == '*')
// 		{
// 			fprintf(fichier, "line = %s\n", line);
// 			s->piece[i] = ft_strdup(line);
// 			ft_strdel(&line);
// 			i++;
// 		}
// 	}
// 	// fprintf(fichier, "s->piece[0] = %s\n", s->piece[0]);
// 	transform_piece(s, fichier);
// }



// int	fill_tab(t_main *s, int *player)
// {
// 	char	*line;
// 	int		i;
// 	char	**split;
// 	FILE 	*fichier;
// 	int		fd;
//
// 	line = NULL;
// 	fichier = fopen("test.txt", "a+");
// 	// fd = STDIN_FILENO;
// 	fd = open("temp.txt", O_RDONLY);
// 	fprintf(fichier, "entree\n");
// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		printf("%s\n", line);
// 		if (line[0] == '$')
// 		{
// 			*player = get_player_nb(line);
// 			fprintf(fichier, "player = %d\n", *player);
// 		}
// 		else if (line[0] == 'P' && line[1] == 'l')
// 		{
// 			if (s->map)
// 				ft_free_tab_str(s->map);
// 			i = 0;
// 			split = ft_strsplit(line, ' ');
// 			s->size_x = ft_atoi(split[2]);
// 			s->size_y = ft_atoi(split[1]);
// 			// fprintf(fichier, "y = %d x = %d\n", s->size_y, s->size_x);
// 			if (!(s->map = malloc(sizeof(char *) * (s->size_y + 1))))
// 				return (0);
// 			ft_bzero((void *)s->map, sizeof(s->map));
// 			ft_free_tab_str(split);
// 		}
// 		else if (ft_isdigit(line[0]))
// 		{
// 			fprintf(fichier, "ligne = %s\n", line);
// 			// printf("%s\n", line);
// 			split = ft_strsplit(line, ' ');
// 			// ft_strdel(&(s->map[i]));
// 			s->map[i++] = ft_strdup(split[1]);
// 			ft_free_tab_str(split);
// 			printf("i\n");
// 			// fprintf(fichier, "%s\n", s->map[i]);
// 		}
// 		else if (line[0] == 'P' && line[1] == 'i')
// 		{
// 			get_piece(s, fichier, line, fd);
// 			set_piece(s);
// 			printf("\n");
// 		}
// 		// if (line)
// 		// 	ft_memdel((void **)&line);
// 	}
// 	fprintf(fichier, "exit\n");
// 	fclose(fichier);
//
// 	// set_piece(s);
// 	return (1);
// }

int	fill_map(t_main *s, int *player, FILE *fichier, int i)
{
	char **split;

	if (s->line[0] == '$' && s->first == 0)
	{
		*player = get_player_nb(s->line);
	}
	else if (s->line[0] == 'P' && s->line[1] == 'l')
	{
		if (s->first == 0)
		{
			split = ft_strsplit(s->line, ' ');
			s->size_x = ft_atoi(split[2]);
			s->size_y = ft_atoi(split[1]);
			// fprintf(fichier, "size_y = %d\n", s->size_y);
			ft_free_tab_str(&split);
		}
		if (!(s->map = malloc(sizeof(char *) * (s->size_y + 1))))
			return (0);
		ft_bzero((void *)(s->map), sizeof(char *) * (s->size_y + 1));
	}
	else if (ft_isdigit(s->line[0]))
	{
		split = ft_strsplit(s->line, ' ');
		// if (!s->map[i]) || (s->map[i] && ft_strcmp(s->map[i], split[1]) != 0))
		// {
		ft_strdel(&(s->map[i]));
		// fprintf(fichier, "i = %d\n",i);
		// fprintf(fichier, "s->line = %s\n", s->line);
		s->map[i] = ft_strdup(split[1]);
		// fprintf(fichier, "s->map [i] = %s\n", s->map[i]);
		// }
		s->i++;
		ft_free_tab_str(&split);
	}
	else if (s->line[0] == 'P' && s->line[1] == 'i')
	{
		// ft_print_words_tables(s->map);
		get_piece(s, fichier, s->fd);
		// printf("\n");
		return (1);
	}
	return (0);
}
// char	*fill_tab(t_main *s, int *player)
// {
// 	char	*line;
// 	char	*tab;
// 	int		i;
// 	char	**split;
// 	FILE *fichier;
// 	FILE *temp;
//
// 	fichier = fopen("test.txt", "a+");
// 	temp = fopen("temp.txt", "r");
//
// 	i = 0;
// 	// tab = ft_strdup("");
// 	while (get_next_line(STDIN_FILENO, &line) > 0)
// 	{
// 		//remplir le player et avancer
// 		if (*player == 0)
// 		{
// 			*player = get_player_nb(line);
// 			fprintf(fichier, "player = %d\n", *player);
// 			ft_memdel((void **)&line);
// 			get_next_line(STDIN_FILENO, &line);
// 		}
// 		//creer le tableau final et avancer
// 		if (s->size_x == 0)
// 		{
// 			split = ft_strsplit(line, ' ');
// 			s->size_x = ft_atoi(split[2]);
// 			s->size_y = ft_atoi(split[1]);
// 			// fprintf(fichier, "y = %d x = %d\n", s->size_y, s->size_x);
// 			if (!(s->map = ft_memalloc(sizeof(char *) * (s->size_y + 1))))
// 				return (NULL);
// 			// s->map[s->size_y + 1] = NULL;
// 			ft_memdel((void **)&split);
// 			ft_memdel((void **)&line);
// 			get_next_line(STDIN_FILENO, &line);
// 			ft_memdel((void **)&line);
// 			get_next_line(STDIN_FILENO, &line);
// 		}
// 		if (i < s->size_y)
// 		{
// 			split = ft_strsplit(line, ' ');
// 			s->map[i] = ft_strdup(split[1]);
// 			tab = s->map[i];
// 			// fprintf(fichier, "%s\n", tab);
// 			// fprintf(fichier, "%s i = %d\n", tab, i);
// 		}
// 		else
// 		{
// 			get_piece(s, fichier, line);
// 			i = 0;
// 			// while (s->new_piece.index[i] != 0)
// 			// {
// 			// 	fprintf(fichier, "numero %d pos.x = %d pos.y = %d\n",s->new_piece.index[i], s->new_piece.coord[i].x, s->new_piece.coord[i].y);
// 			// 	i++;
// 			// }
// 			break ;
// 		}
// 		i++;
// 	}
// 	fprintf(fichier, "exit\n");
// 	fclose(fichier);
// 	return (tab);
// }
