/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:37:17 by jgehin            #+#    #+#             */
/*   Updated: 2019/06/22 17:12:46 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_nbrlen(long long nb)
{
	int res;

	res = 1;
	if (nb > 999999999999999999)
		return (19);
	if (nb == 0)
		return (1);
	while (nb > 9)
	{
		nb /= 10;
		res++;
	}
	return (res);
}
