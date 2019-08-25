/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:29:44 by ydonse            #+#    #+#             */
/*   Updated: 2019/08/25 16:39:39 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"



typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_map
{
	int				x;
	int				y;
	char			**tab;
}					t_map;

typedef struct  s_main
{
	int	board_x;
	int	board_y;

}				t_main;
#endif
