/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:58:28 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <stdio.h>

int		libx_get_color_in_image(t_libx_img *img, int x, int y)
{
	int		c;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	c = *(int*)(img->buffer
			+ (x * (img->bits_per_pixel >> 3) + y * img->size_line));
	c = c & 0x00FFFFFF;
	return (c);
}
