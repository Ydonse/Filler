/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:26:55 by ydonse            #+#    #+#             */
/*   Updated: 2019/08/27 14:48:50 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char *tab;
	t_main s;

	s.player = get_player_nb(&s);
	tab = fill_tab();
	//s.board = get_board_size(&s);
	while (1)
	{
		//get_piece
		//place_piece
		//return_piece_pos
	}
	ft_putstr(tab);

	// ft_putstr(tab);
	return(0);
}
