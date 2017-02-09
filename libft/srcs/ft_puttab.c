/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 17:08:04 by tettouat          #+#    #+#             */
/*   Updated: 2015/01/20 16:44:40 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_puttabl(char **tabl)
{
	int		i;

	i = 0;
	while (tabl[i] != '\0')
	{
		ft_putendl(tabl[i]);
		i++;
	}
}