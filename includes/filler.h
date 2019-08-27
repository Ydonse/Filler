/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:29:44 by ydonse            #+#    #+#             */
/*   Updated: 2019/08/27 14:44:20 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"



typedef enum		e_player
{
	p1,
	p2
}					t_player;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_map
{
	int				x;
	int				y;
	char			*tab;
}					t_map;

typedef struct  	s_main
{
	t_pos			board;
	t_player		player;


}					t_main;

int					get_player_nb(t_main *s);
char				*fill_tab();

#endif
