/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:58:00 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

int		libx_color_to_int(t_libx_color color)
{
	return ((((int)color.r & 0xFF) << 0x10) +
			(((int)color.g & 0xFF) << 0x08) +
			(((int)color.b & 0xFF) << 0x00));
}
