/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:08:47 by ydonse            #+#    #+#             */
/*   Updated: 2020/03/06 11:58:53 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_tab_str(char ***tab)
{
	int i;

	if (*tab)
	{
		i = 0;
		while ((*tab)[i])
			ft_strdel(&((*tab)[i++]));
		free(*tab);
		*tab = NULL;
	}

}
