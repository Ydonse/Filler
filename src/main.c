/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:26:55 by ydonse            #+#    #+#             */
/*   Updated: 2020/02/11 16:01:23 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char 	*tab;
	t_main 	s;
	int		fd;

	s.player = get_player_nb(&s);
	tab = fill_tab();
	fd = open();
	//s.board = get_board_size(&s);
	// while (1)
	// {
	// 	//get_piece
	// 	//place_piece
	// 	//return_piece_pos
	// }
	ft_putstr(tab);
	write(1, tab, ft_strlen(tab));

	// ft_putstr(tab);
	return(0);
}
