/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:21:22 by ydonse            #+#    #+#             */
/*   Updated: 2019/08/27 13:34:48 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_player_nb(t_main *s)
{
	char *line;

	get_next_line(STDIN_FILENO, &line);
	if(strstr(line, "ydonse"))
	{
		if (strstr(line, "p1"))
			s->player = p1;
		else
			s->player = p2;
	}
	return (0);
}

char	*fill_tab()
{
	char	*line;
	char	*tab;
	int		i;

	i = 0;
	tab = ft_strdup("");
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		tab = ft_strjoin_free(&tab, &line);
		i++;
	}

	return (tab);
}
