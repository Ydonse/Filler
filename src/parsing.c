/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:21:22 by ydonse            #+#    #+#             */
/*   Updated: 2020/03/02 18:28:27 by ydonse           ###   ########.fr       */
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

char	*fill_tab(int *player)
{
	char	*line;
	char	*tab;
	char	*newline;
	int		i;
	int		x;
	int		y;
	char	**split;
	char	**map;
	FILE *fichier;

	// fd = open("test.test", O_RDWR);
	fichier = fopen("test.txt", "a+");

	i = 0;
	x = 0;
	y = 0;
	tab = ft_strdup("");
	newline = ft_strdup("\n");
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		//remplir le player et avancer
		if (*player == 0)
		{
			*player = get_player_nb(line);
			fprintf(fichier, "player = %d\n", *player);
			ft_memdel((void **)&line);
			get_next_line(STDIN_FILENO, &line);
		}
		//creer le tableau final et avancer
		if (x == 0)
		{
			split = ft_strsplit(line, ' ');
			x = ft_atoi(split[1]);
			y = ft_atoi(split[2]);
			if (!(map = ft_memalloc(sizeof(char *) * y)))
				return (NULL);
			ft_memdel((void **)&split);
			ft_memdel((void **)&line);
			get_next_line(STDIN_FILENO, &line);
			ft_memdel((void **)&line);
			get_next_line(STDIN_FILENO, &line);
		}
		split = ft_strsplit(line, ' ');
		if (i < y)
			map[i] = split[1];
		tab = ft_strjoin(map[i], newline);
		fprintf(fichier, "%s", tab);
		i++;
	}

	// fprintf(fichier, "%s\n", tab);
	fclose(fichier);
	return (tab);
}
