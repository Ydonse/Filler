/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:26:55 by ydonse            #+#    #+#             */
/*   Updated: 2019/08/25 17:28:46 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(int argc, char **argv)
{
	char *line;

	while (get_next_line(0, &line))
		write(1, line, ft_strlen(line));
	return(0);
}
