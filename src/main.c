/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:26:55 by ydonse            #+#    #+#             */
/*   Updated: 2020/02/14 17:16:46 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	// char 	*tab;
	t_main 	*s;

	// ft_bzero((void **)&s, sizeof(t_main));
	if (!(s = (t_main*)malloc(sizeof(t_main))))
		return (0);
	ft_bzero((void*)s, sizeof(t_main));
	display_visu(s);
	// s.player = get_player_nb(&s);
	// tab = fill_tab();
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
