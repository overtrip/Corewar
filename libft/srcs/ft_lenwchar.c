/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:34:56 by tettouat          #+#    #+#             */
/*   Updated: 2015/11/24 16:35:06 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenwchar(wint_t x)
{
	size_t			j;

	j = 1;
	if (x <= 0x7F)
		return (j);
	if (x > 0x1FFFFF)
		return (-1);
	while (1)
	{
		if (!(x >>= 6))
			break ;
		j++;
	}
	return (j);
}
