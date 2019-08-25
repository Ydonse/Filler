/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:21:22 by ydonse            #+#    #+#             */
/*   Updated: 2019/08/25 16:41:17 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_lines_size(t_map *m)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (!m->grid[i])
		return (0);
	while (m->grid[i][j])
		j++;
	while (m->grid[i])
	{
		while (m->grid[i][k])
			k++;
		if (k != j)
			return (0);
		k = 0;
		i++;
	}
	return (1);
}

int		check_nb(char *tab)
{
	int i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (tab[i] != '-' && tab[i] != '\r' && tab[i] != ' ' &&
				ft_isdigit((int)tab[i]) == 0)
		{
			ft_strdel(&tab);
			return (0);
		}
		i++;
	}
	return (1);
}

int		fill_grid(char **tab, t_map *m, int i, int j)
{
	while (tab[j])
		j++;
	m->size_x = j;
	m->space = m->size_x > m->size_y ?
		WIN_X / m->size_x * 0.7 : WIN_Y / m->size_y * 0.7;
	m->depth = 5;
	j = 0;
	if (!(m->grid[i] = malloc(sizeof(t_point*) * (m->size_x + 1))) || !tab[j])
		return (0);
	while (tab[j])
	{
		if (!(m->grid[i][j] = malloc(sizeof(t_point))) || !(check_nb(tab[j])))
			return (0);
		m->grid[i][j]->x = m->ori_x + (j * m->space);
		m->grid[i][j]->y = m->ori_y + (i * m->space);
		m->grid[i][j]->ori_z = ft_atoi(tab[j]);
		m->grid[i][j]->z = m->grid[i][j]->ori_z * m->depth;
		m->max_z = m->grid[i][j]->z > m->max_z ? m->grid[i][j]->z : m->max_z;
		m->min_z = m->grid[i][j]->z < m->min_z ? m->grid[i][j]->z : m->min_z;
		if (m->max_z / m->depth - m->min_z / m->depth > 500)
			return (0);
		j++;
	}
	m->grid[i][j] = NULL;
	return (1);
}

int		convert_tab(char **tab, t_map *m, int i, int j)
{
	char	**temp;

	while (tab[i])
		i++;
	if (!(m->grid = malloc(sizeof(t_point *) * i + 1)))
		return (0);
	m->grid[i] = NULL;
	m->size_y = i;
	m->max_z = 0;
	m->min_z = 0;
	m->ori_y = 0;
	m->ori_x = 0;
	while (tab[j])
	{
		temp = ft_strsplit(tab[j], ' ');
		if (!(fill_grid(temp, m, j++, 0)))
		{
			ft_free_tab_str(temp);
			return (0);
		}
		ft_free_tab_str(temp);
	}
	m->mode = ft_strdup("plane");
	ft_free_tab_str(tab);
	return (1);
}

int		fill_tab(char **argv, t_map *m, int i, int fd)
{
	char	*line;
	char	**tab;

	while (get_next_line(fd, &line))
	{
		if (check_nb(line) == 0)
			return (0);
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!(tab = malloc(sizeof(char *) * (i + 1))))
		return (0);
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		return (0);
	i = 0;
	while (get_next_line(fd, &line))
		tab[i++] = ft_strdup_free(&line);
	tab[i] = NULL;
	if (!(convert_tab(tab, m, 0, 0)) || check_lines_size(m) == 0)
		return (0);
	ft_strdel(&line);
	return (1);
}
