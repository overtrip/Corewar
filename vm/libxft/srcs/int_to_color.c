/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:58:46 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

t_libx_color	libx_int_to_color(int color)
{
	t_libx_color	c;

	c = (t_libx_color){
			.r = ((int)color >> 0x10) & 0xFF,
			.g = ((int)color >> 0x08) & 0xFF,
			.b = ((int)color >> 0x00) & 0xFF
			};
	return (c);
}
