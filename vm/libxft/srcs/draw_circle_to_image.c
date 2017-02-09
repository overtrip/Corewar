/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_to_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:58:11 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdarg.h>

static void		s_draw_circle(t_libx_img *img, int data[5])
{
	int		x;
	int		y;

	x = -(data[2] / 2);
	while (x < (data[2] / 2))
	{
		y = -(data[3] / 2);
		while (y < (data[3] / 2))
		{
			if (x * x + y * y <= (data[2] / 2) * (data[3] / 2))
				libx_put_pixel_to_image(img, x + data[0] + (data[2] / 2),
						y + data[1] + (data[3] / 2), data[4]);
			++y;
		}
		++x;
	}
}

void			libx_draw_circle_to_image(t_libx_img *img, ...)
{
	va_list		args;
	int			data[5];
	int			i;

	if (img == NULL)
		return ;
	va_start(args, img);
	i = 0;
	while (i < 5)
	{
		data[i] = (int)va_arg(args, int);
		++i;
	}
	va_end(args);
	s_draw_circle(img, data);
	return ;
}
